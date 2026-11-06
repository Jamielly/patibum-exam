# 42 Exam Shell (Python)

Simulador de prova no estilo do `42_examshell`, em Python. Você escolhe um
exercício, escreve a solução na pasta `rendu/`, o shell roda os exemplos e
mostra o que passou e o que falhou. A solução de referência fica disponível
para consulta (com confirmação).

## Uso

```bash
python3 exam.py
```

Comandos do menu:

| Comando   | Ação                                           |
|-----------|------------------------------------------------|
| `g <n>`   | corrige `rendu/<arquivo>` contra os exemplos   |
| `s <n>`   | mostra o enunciado e a assinatura              |
| `r <n>`   | recria o arquivo em `rendu/` com o template    |
| `x <n>`   | mostra a solução (pede confirmação)            |
| `w`       | mostra o caminho da pasta de trabalho          |
| `q`       | sai                                            |

O progresso (exercícios validados) fica em `.progress.json`.

## Como funciona

- Cada exercício é um arquivo em `exercises/rank03/` com `FILENAME`,
  `FUNCTION`, `ASSIGNMENT`, `SIGNATURE` e `TESTS`.
- A correção roda o seu arquivo em um processo separado, com timeout de
  5 segundos, então loops infinitos e erros não derrubam o shell.
- Os testes devem ser valores serializáveis em JSON (listas, inteiros,
  strings, booleanos, `None`). Tuplas viram listas, então se a sua função
  retorna tupla, compare com uma lista no teste ou adapte o runner.

## Adicionando as subjects

1. Copie `exercises/rank03/ft_sum_positive.py` para um novo arquivo, por
   exemplo `exercises/rank03/ft_nome.py`.
2. Preencha `FILENAME`, `FUNCTION`, `ASSIGNMENT`, `SIGNATURE` e `TESTS`
   com os dados da subject (use os exemplos de entrada e saída dela).
3. Escreva a solução em `solutions/rank03/ft_nome.py`.
4. Reinicie `exam.py`. O novo exercício aparece automaticamente na lista.

Os enunciados e exemplos devem ser preenchidos por você a partir da
subject oficial ou do site de referência, para ficar fiel à prova.

## Requisitos

- Python 3.9 ou superior (os tipos `list[int]` precisam de 3.9+)
- Linux, macOS ou WSL
