#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <iomanip>
#include <windows.h>

#define TAM 1000

using namespace std;

struct venda_com_nota
{
    int id_produto;
    float valor_de_venda;
    int codigo_nota;
};

bool verPorId(venda_com_nota ops[TAM], int cont);
bool verPorCodigo(venda_com_nota ops[TAM], int cont);
bool verVendasNota(venda_com_nota vendas[TAM], int cont);
bool cadastrarVendaNota(venda_com_nota venda, venda_com_nota vendas[TAM], int cont);
venda_com_nota capturarVenda();

int main()
{

    setlocale(LC_ALL, "Portuguese");

    int menu, contador_de_vendas = 0, vezes = 0;

    venda_com_nota vendas[TAM];
    venda_com_nota aux;

    do
    {
        system("cls");
        cout << "---------------------------------------- \n";
        cout << "- Bem Vindo ao Gerador de Notas Fiscais- \n";
        cout << "---------------------------------------- \n";
        cout << "1 - Para gerar venda com nota fiscal   - \n";
        cout << "2 - Para ver Notas                     - \n";
        cout << "3 - Procurar por Codigo                - \n";
        cout << "4 - Procurar por Id do Produto         - \n";
        cout << "5 - Para Sair                          - \n";
        cout << "---------------------------------------- \n\n\n";
        if (vezes == 0)
        {
            cout << "-----------------------------------------------------------------\n";
            cout << "Desenvolvido por: Gilberto da Rocha Caires                      -\n";
            cout << "Atualmente cursando 1 Ano Informatica no IFBA - Campus Brumado  -\n";
            cout << "-----------------------------------------------------------------\n";

        }

        menu = getch();

        switch (menu)
        {
        case '1':
            system("cls");
            aux = capturarVenda();
            if (cadastrarVendaNota(aux, vendas, contador_de_vendas))
            {
                system("cls");
                cout << "Cadastrado com Sucesso! \n";
                contador_de_vendas++;
            }
            else
            {
                cout << "ERRO NO CADASTRO\n";
            }
            system("pause");
            break;
        case '2':
            system("cls");
            if (contador_de_vendas == 0)
            {
                cout << "Não foi registrado nenhuma nota!\n";
            }
            else
            {
                verVendasNota(vendas, contador_de_vendas);
            }
            system("pause");
            break;
        case '3':
            system("cls");
            if (verPorCodigo(vendas, contador_de_vendas))
            {
            }
            else
            {
                cout << "ERRO!";
            }
            system("pause");
            break;
        case '4':
            system("cls");
            if (verPorId(vendas, contador_de_vendas))
            {
            }
            else
            {
                cout << "ERRO!";
            }
            system("pause");
            break;
        case '5':
            system("cls");
            cout << "Obrigado pela Preferência !\n";
            exit(1);
            break;
        default:
            system("cls");
            cout << "Informe uma opção válida! \n";
            system("pause");
            break;
        }
        vezes++;
    } while (true);
}

venda_com_nota capturarVenda()
{

    venda_com_nota temp;

    cout << "Informe o ID do Produto .=";
    cin >> temp.id_produto;
    cout << "Informe o Valor do Produto .=";
    cin >> temp.valor_de_venda;

    unsigned seed = time(0);
    srand(seed);

    temp.codigo_nota = rand();

    return temp;
}

bool cadastrarVendaNota(venda_com_nota venda, venda_com_nota vendas[TAM], int cont)
{
    vendas[cont].id_produto = venda.id_produto;
    vendas[cont].valor_de_venda = venda.valor_de_venda;
    vendas[cont].codigo_nota = venda.codigo_nota;

    return true;
}

bool verVendasNota(venda_com_nota ops[TAM], int cont)
{
    cout << "---------------------- LISTA --------------------\n";
    cout << "Id_Produto ------------Valor --------- Codigo ---\n";
    for (int i = 0; i < cont; i++)
    {
        cout << ops[i].id_produto << setw(25) << ops[i].valor_de_venda << setw(20) << ops[i].codigo_nota << setw(3) << "\n";
    }
    cout << "-------------------------------------------------\n";

    return true;
}
bool verPorCodigo(venda_com_nota ops[TAM], int cont)
{
    int codigo, registros = 0;

    cout << "Informe o Codigo para procurar: ";
    cin >> codigo;
    system("cls");
    cout << "\nProcurando.";
    Sleep(1000);
    system("cls");
    cout << "\nProcurando..";
    Sleep(1000);
    system("cls");
    cout << "\nProcurando...";
    Sleep(1000);
    system("cls");

    cout << "---------------------- LISTA --------------------\n";
    cout << "Id_Produto ------------Valor --------- Codigo ---\n";
    for (int i = 0; i < cont; i++)
    {
        if (ops[i].codigo_nota == codigo)
        {
            cout << ops[i].id_produto << setw(25) << ops[i].valor_de_venda << setw(20) << ops[i].codigo_nota << setw(3) << "\n";
            registros++;
        }
    }
    if (registros == 0)
    {
        cout << "Não Possui venda com esse codigo\n";
    }
    cout << "-------------------------------------------------\n";

    return true;
}
bool verPorId(venda_com_nota ops[TAM], int cont)
{
    int id, registros = 0;

    cout << "Informe o Id para procurar: ";
    cin >> id;
    system("cls");
    cout << "\nProcurando.";
    Sleep(1000);
    system("cls");
    cout << "\nProcurando..";
    Sleep(1000);
    system("cls");
    cout << "\nProcurando...";
    Sleep(1000);
    system("cls");

    cout << "---------------------- LISTA --------------------\n";
    cout << "Id_Produto ------------Valor --------- Codigo ---\n";
    for (int i = 0; i < cont; i++)
    {
        if (ops[i].id_produto == id)
        {
            cout << ops[i].id_produto << setw(25) << ops[i].valor_de_venda << setw(20) << ops[i].codigo_nota << setw(3) << "\n";
            registros++;
        }
    }
    if (registros == 0)
    {
        cout << "Não Possui venda com esse id\n";
    }
    cout << "-------------------------------------------------\n";

    return true;
}
