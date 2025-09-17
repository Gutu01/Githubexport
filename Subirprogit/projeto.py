
print("Boas-vindas!")
nome = input("Digite seu nome:")
idade = int(input("Digite sua idade:"))

if idade >= 18:
    print("\n1- Realizar cadastro")
    print("0-Finalizar atendimento")
    resposta = int(input("Resposta:"))

    if resposta == 1:

        deposito = float(input("Realize um depósito para finalizar o cadastro:"))

        print("1-Sacar")
        print("0-Sair")

        resposta2 = int(input("Resposta:"))

        if resposta2 == 1:
            saque = float(input("Valor do saque:"))
            deposito = deposito - saque
            print("Saldo final:", deposito)
        else:
            print("Saldo final: ", deposito)
            exit;

    else:

        exit;

else:
    print("\nSai daqui pirralho!\n")