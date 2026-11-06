# 42 Exam Shell (Python) - Ranks 03 a 06

Simulador de prova em Python. Todos os exercícios dos ranks 03, 04, 05 e 06
aparecem numa lista única. Você escreve a solução em `rendu/`, o shell roda os
exemplos e mostra o que passou e o que falhou. A solução de referência fica
disponível com confirmação.

## Uso

```bash
python3 exam.py
```

| Comando | Ação                                         |
|---------|----------------------------------------------|
| `g <n>` | corrige `rendu/<arquivo>` contra os exemplos |
| `s <n>` | mostra o enunciado e a assinatura            |
| `r <n>` | recria o arquivo em `rendu/` com o template  |
| `x <n>` | mostra a solução (pede confirmação)          |
| `w`     | mostra a pasta de trabalho                   |
| `q`     | sai                                          |

O progresso fica em `.progress.json`.

## Estrutura

```
exercises/rank03/*.py   enunciado, assinatura e testes
exercises/rank04/*.py
exercises/rank05/*.py
exercises/rank06/*.py
solutions/rankXX/*.py   soluções de referência
rendu/                  onde você escreve
```

Os exercícios de exemplo em cada rank são originais, escritos só para testar o
fluxo. Não são as subjects oficiais.

## Adicionando as subjects reais

1. Copie um arquivo de `exercises/<rank>/` e renomeie.
2. Preencha `FILENAME`, `FUNCTION`, `ASSIGNMENT`, `SIGNATURE` e `TESTS` com a
   subject (use os exemplos de entrada e saída dela).
3. Escreva a solução em `solutions/<rank>/` com o mesmo nome.
4. Reinicie `exam.py`.

Em `TESTS`, cada item é `(lista_de_argumentos, resultado_esperado)`. Os valores
precisam ser serializáveis em JSON. Tuplas viram listas, então adapte o teste
ou o runner se a função retornar tupla.

## Requisitos

- Python 3.9+
- Linux, macOS ou WSL
