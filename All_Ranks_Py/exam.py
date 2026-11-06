#!/usr/bin/env python3
"""42 Exam Practice Shell (Python) - Ranks 03, 04, 05 and 06.

All exercises from all ranks are listed together. Write your solution in
rendu/, grade it, and optionally reveal the reference solution.

Run with:  python3 exam.py
"""

import importlib.util
import json
import subprocess
import sys
import tempfile
import time
from pathlib import Path

ROOT = Path(__file__).resolve().parent
EXERCISES = ROOT / "exercises"
SOLUTIONS = ROOT / "solutions"
RANKS = ["rank03", "rank04", "rank05", "rank06"]
RENDU = ROOT / "rendu"
PROGRESS_FILE = ROOT / ".progress.json"
TIMEOUT = 5  # seconds allowed per grading run

# Runs the student's file in a separate process so crashes and infinite
# loops cannot take the shell down.
RUNNER = r'''
import importlib.util, json, sys
student_path, func_name, tests_path, out_path = sys.argv[1:5]
with open(tests_path) as f:
    tests = json.load(f)
spec = importlib.util.spec_from_file_location("student", student_path)
mod = importlib.util.module_from_spec(spec)
spec.loader.exec_module(mod)
fn = getattr(mod, func_name)
results = []
for args, expected in tests:
    try:
        got = fn(*args)
        results.append({"ok": got == expected, "got": repr(got)})
    except Exception as exc:
        results.append({"ok": False, "got": f"{type(exc).__name__}: {exc}"})
with open(out_path, "w") as f:
    json.dump(results, f)
'''


# ---------------------------------------------------------------- loading

def load_exercises():
    """Import every exercises/<rank>/*.py file, in rank order."""
    exercises = []
    for rank in RANKS:
        folder = EXERCISES / rank
        if not folder.is_dir():
            continue
        for path in sorted(folder.glob("*.py")):
            spec = importlib.util.spec_from_file_location(f"{rank}_{path.stem}", path)
            module = importlib.util.module_from_spec(spec)
            spec.loader.exec_module(module)
            module.RANK = rank
            module.KEY = f"{rank}/{module.FILENAME}"
            exercises.append(module)
    return exercises


def load_progress():
    if PROGRESS_FILE.exists():
        return set(json.loads(PROGRESS_FILE.read_text()))
    return set()


def save_progress(done):
    PROGRESS_FILE.write_text(json.dumps(sorted(done), indent=2))


# ---------------------------------------------------------------- grading

def grade(ex):
    """Run rendu/<FILENAME> against ex.TESTS. Returns (passed, lines)."""
    student_file = RENDU / ex.FILENAME
    if not student_file.exists():
        return False, [f"rendu/{ex.FILENAME} does not exist yet. Write your solution there first."]

    with tempfile.TemporaryDirectory() as tmp:
        tmp = Path(tmp)
        tests_path = tmp / "tests.json"
        runner_path = tmp / "runner.py"
        out_path = tmp / "out.json"
        tests_path.write_text(json.dumps(ex.TESTS))
        runner_path.write_text(RUNNER)

        try:
            proc = subprocess.run(
                [sys.executable, str(runner_path), str(student_file),
                 ex.FUNCTION, str(tests_path), str(out_path)],
                capture_output=True, text=True, timeout=TIMEOUT, cwd=RENDU,
            )
        except subprocess.TimeoutExpired:
            return False, [f"Timed out after {TIMEOUT}s. Infinite loop?"]

        if proc.returncode != 0 or not out_path.exists():
            last = (proc.stderr.strip().splitlines() or ["unknown error"])[-1]
            return False, [f"Could not run {ex.FILENAME}: {last}",
                           f"(Is the function named '{ex.FUNCTION}'?)"]

        results = json.loads(out_path.read_text())

    lines = []
    all_ok = True
    for (args, expected), res in zip(ex.TESTS, results):
        call = f"{ex.FUNCTION}({', '.join(repr(a) for a in args)})"
        lines.append(f"  [{'OK  ' if res['ok'] else 'KO  '}] {call}")
        if not res["ok"]:
            all_ok = False
            lines.append(f"         expected: {expected!r}")
            lines.append(f"         got:      {res['got']}")
    return all_ok, lines


# ---------------------------------------------------------------- actions

def show_subject(ex):
    print(f"\n=== [{ex.RANK}] {ex.FILENAME} ===")
    print(ex.ASSIGNMENT.strip())
    print(f"\nFunction signature:\n  {ex.SIGNATURE}")
    print(f"\nWrite it in: rendu/{ex.FILENAME}")


def reset_rendu(ex):
    answer = input(f"Overwrite rendu/{ex.FILENAME} with the template? [y/N] ").strip().lower()
    if answer != "y":
        print("Cancelled.")
        return
    (RENDU / ex.FILENAME).write_text(f"{ex.SIGNATURE}\n    pass\n")
    print(f"rendu/{ex.FILENAME} reset.")


def show_solution(ex):
    path = SOLUTIONS / ex.RANK / ex.FILENAME
    if not path.exists():
        print("No solution available for this exercise.")
        return
    answer = input("Revealing the solution defeats the purpose. Type 'yes' to continue: ").strip().lower()
    if answer != "yes":
        print("Good call. Back to it.")
        return
    print(f"\n--- solutions/{ex.RANK}/{ex.FILENAME} ---")
    print(path.read_text())


# ---------------------------------------------------------------- menu

def pick(exercises, arg):
    try:
        index = int(arg) - 1
        if 0 <= index < len(exercises):
            return exercises[index]
    except (TypeError, ValueError):
        pass
    print("Invalid exercise number.")
    return None


def print_menu(exercises, done, started):
    elapsed = int((time.time() - started) / 60)
    print("\n" + "=" * 56)
    print(f" 42 EXAM SHELL - Python ranks 03-06     elapsed: {elapsed} min")
    print(f" Progress: {len(done)}/{len(exercises)} validated")
    print("=" * 56)
    current_rank = None
    for i, ex in enumerate(exercises, 1):
        if ex.RANK != current_rank:
            current_rank = ex.RANK
            print(f"\n {current_rank.upper()}")
        mark = "[OK]" if ex.KEY in done else "[  ]"
        print(f"  {i:2}. {mark} {ex.FILENAME}")
    print("\n g <n> grade     s <n> show subject")
    print(" r <n> reset     x <n> show solution")
    print(" w     workspace info          q  quit")


def main():
    RENDU.mkdir(exist_ok=True)
    exercises = load_exercises()
    if not exercises:
        print(f"No exercises found in {EXERCISES}")
        return

    done = load_progress()
    started = time.time()

    while True:
        print_menu(exercises, done, started)
        parts = input("\n> ").strip().split()
        if not parts:
            continue
        cmd = parts[0].lower()
        arg = parts[1] if len(parts) > 1 else None

        if cmd == "q":
            print("Good luck on the exam!")
            break
        elif cmd == "w":
            print(f"\nWorkspace: {RENDU}")
            print("Every rank is graded from this folder, like the rendu folder in the real exam.")
        elif cmd in ("g", "s", "r", "x"):
            ex = pick(exercises, arg)
            if ex is None:
                continue
            if cmd == "s":
                show_subject(ex)
            elif cmd == "r":
                reset_rendu(ex)
            elif cmd == "x":
                show_solution(ex)
            else:
                print(f"\nGrading rendu/{ex.FILENAME} ...")
                passed, lines = grade(ex)
                print("\n".join(lines))
                if passed:
                    print("\nVALIDATED")
                    done.add(ex.KEY)
                    save_progress(done)
                else:
                    print("\nFAILED")
        else:
            print("Unknown command.")


if __name__ == "__main__":
    try:
        main()
    except (KeyboardInterrupt, EOFError):
        print("\nBye.")
