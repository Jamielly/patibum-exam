# cifra de cesar - amei

def whisper_cipher(text: str, shift: int) -> str:
    result = []

    for char in text:
        if 'a' <= char <= 'z':
            # Base 0 a 25 para minúsculas
            offset = ord(char) - ord('a')
            new_char = chr(ord('a') + (offset + shift) % 26)
            result.append(new_char)
        elif 'A' <= char <= 'A' + 25:  # ou 'A' <= char <= 'Z'
            # Base 0 a 25 para maiúsculas
            offset = ord(char) - ord('A')
            new_char = chr(ord('A') + (offset + shift) % 26)
            result.append(new_char)
        else:
            # Mantém números, pontuação e espaços inalterados
            result.append(char)
    return "".join(result)
