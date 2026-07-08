#include <stdio.h>
#include <strings.h>

typedef struct {
    int vagamanha[6];
    int vagatarde[6];
    char nomepacientemanha[6][50];
    char nomepacientetarde[6][50];
    char cpfpacientemanha[6][12];
    char cpfpacientetarde[6][12];
} Turnos;

typedef struct {
    char nomeEspecialidade[30];
    Turnos status;
} Especialidade;

typedef struct {
    char nome[50];
    int qtdEspecialidades;
    Especialidade listaEspecialidades[5];
} Agencias;

int main() {
    Agencias listaAgencias[4] = {
        {"Recife", 5, {
            {"Cardiologia", {{1,1,1,1,1,1}, {1,1,1,1,1,1}, "", ""}},
            {"Odontologia", {{1,1,1,1,1,1}, {1,1,1,1,1,1}, "", ""}},
            {"Clinico Geral", {{1,1,1,1,1,1}, {1,1,1,1,1,1}, "", ""}},
            {"Pediatra", {{1,1,1,1,1,1}, {1,1,1,1,1,1}, "", ""}},
            {"Ortopedista", {{1,1,1,1,1,1}, {1,1,1,1,1,1}, "", ""}}
        }},
        {"Olinda", 4, {
            {"Clinico Geral", {{1,1,1,1,1,1}, {1,1,1,1,1,1}, "", ""}},
            {"Oftalmologista", {{1,1,1,1,1,1}, {1,1,1,1,1,1}, "", ""}},
            {"Cardiologia", {{1,1,1,1,1,1}, {1,1,1,1,1,1}, "", ""}},
            {"Ortopedista", {{1,1,1,1,1,1}, {1,1,1,1,1,1}, "", ""}}
        }},
        {"Paulista", 3, {
            {"Clinico Geral", {{1,1,1,1,1,1}, {1,1,1,1,1,1}, "", ""}},
            {"Oftalmologista", {{1,1,1,1,1,1}, {1,1,1,1,1,1}, "", ""}},
            {"Pediatra", {{1,1,1,1,1,1}, {1,1,1,1,1,1}, "", ""}}
        }},
        {"Camaragibe", 3, {
            {"Clinico Geral", {{1,1,1,1,1,1}, {1,1,1,1,1,1}, "", ""}},
            {"Oftalmologista", {{1,1,1,1,1,1}, {1,1,1,1,1,1}, "", ""}},
            {"Psiquiatra", {{1,1,1,1,1,1}, {1,1,1,1,1,1}, "", ""}}
        }}
    };

    int opcao;
    int escolhaOpcaoAgencia;
    int escolhaOpcaoEspecialidade;

    printf("\n=============================================\n");
    printf("••••••••••••••••••••C-MED••••••••••••••••••••\n");
    printf("=============================================\n");
    printf("Ola seja bem vindo a central de agencias cMed\n");

    do {
        printf("\nDigite a opcao desejada\n");
        printf("1: Visualizar opcoes de agencia e especialidades.\n");
        printf("2: Agendar Atendimento (Horarios e Vagas).\n");
        printf("0: Sair.\n");
        scanf(" %d", &opcao);

        switch(opcao) {
            case 1:
                printf("\nEscolha a agencia desejada:\n");
                for (int i = 0; i < 4; i++) {
                    printf("%d: %s\n", i + 1, listaAgencias[i].nome);
                }
                printf("Sua escolha: ");
                scanf("%d", &escolhaOpcaoAgencia);
                
                if (escolhaOpcaoAgencia >= 1 && escolhaOpcaoAgencia <= 4) {
                    int agRef = escolhaOpcaoAgencia - 1; 
                    printf("\nAtendimentos disponiveis em %s:\n", listaAgencias[agRef].nome);
                    for (int e = 0; e < listaAgencias[agRef].qtdEspecialidades; e++) {
                        printf("- %s\n", listaAgencias[agRef].listaEspecialidades[e].nomeEspecialidade);
                    }
                } else {
                    printf("\nOpcao de agencia invalida!\n");
                }
                break;

            case 2:
                printf("\nEscolha a agencia para agendamento:\n");
                for (int i = 0; i < 4; i++) {
                    printf("%d: %s\n", i + 1, listaAgencias[i].nome);
                }
                printf("Sua escolha: ");
                scanf("%d", &escolhaOpcaoAgencia);

                if (escolhaOpcaoAgencia >= 1 && escolhaOpcaoAgencia <= 4) {
                    int indiceAgencia = escolhaOpcaoAgencia - 1;
                    printf("\nEscolha a especialidade desejada em %s:\n", listaAgencias[indiceAgencia].nome);
                    for (int e = 0; e < listaAgencias[indiceAgencia].qtdEspecialidades; e++) {
                        printf("%d: %s\n", e + 1, listaAgencias[indiceAgencia].listaEspecialidades[e].nomeEspecialidade);
                    }
                    printf("Sua escolha: ");
                    scanf("%d", &escolhaOpcaoEspecialidade);
                    if (escolhaOpcaoEspecialidade < 1 || escolhaOpcaoEspecialidade > listaAgencias[indiceAgencia].qtdEspecialidades) {
                        printf("\nOpcao de especialidade invalida!\n");
                        break;
                    }

                    int indiceEspecialidade = escolhaOpcaoEspecialidade - 1;
                    if (indiceAgencia == 0 || indiceAgencia == 2) {
                        printf("\nHorarios disponiveis: Manha (8:00 as 10:00) e Tarde (13:00 as 16:00)\n");
                    } else if (indiceAgencia == 1) {
                        printf("\nHorarios disponiveis: Manha (9:00 as 11:00) e Tarde (13:00 as 15:00)\n");
                    } else if (indiceAgencia == 3) {
                        printf("\nHorarios disponiveis: Manha (9:00 as 11:00) e Tarde (13:00 as 16:00)\n");
                    }

                    int agendarvaga;
                    do {
                        printf("\nDeseja agendar?\n1: SIM\n2: NAO\n");
                        scanf(" %d", &agendarvaga);

                        if (agendarvaga == 1) {
                            int turnoEscolhido;
                            printf("\nQual Horario voce deseja?\n1: Manha\n2: Tarde\n");
                            scanf(" %d", &turnoEscolhido);

                            Especialidade *espAtual = &listaAgencias[indiceAgencia].listaEspecialidades[indiceEspecialidade];

                            if (turnoEscolhido == 1) {
                                int vagaEncontrada = -1;
                                for(int v = 0; v < 6; v++) {
                                    if (espAtual->status.vagamanha[v] == 1) {
                                        vagaEncontrada = v;
                                        break;
                                    }
                                }

                                if (vagaEncontrada != -1) {
                                    espAtual->status.vagamanha[vagaEncontrada] = 0; 
                                    printf("\nDigite o nome do paciente para cadastro: \n");
                                    scanf(" %49[^\n]", espAtual->status.nomepacientemanha[vagaEncontrada]);
                                    printf("\nDigite seu CPF: \n");
                                    scanf(" %11s", espAtual->status.cpfpacientemanha[vagaEncontrada]);

                                    printf("\nAgendamento confirmado (Manha) para o paciente %s na especialidade %s!\n", 
                                           espAtual->status.nomepacientemanha[vagaEncontrada], espAtual->nomeEspecialidade);
                                } else {
                                    printf("\nDesculpe, todas as 6 vagas da manha para esta especialidade estao ocupadas!\n");
                                }
                            } else if (turnoEscolhido == 2) {
                                int vagaEncontrada = -1;
                                for(int v = 0; v < 6; v++) {
                                    if (espAtual->status.vagatarde[v] == 1) {
                                        vagaEncontrada = v;
                                        break;
                                    }
                                }

                                if (vagaEncontrada != -1) {
                                    espAtual->status.vagatarde[vagaEncontrada] = 0;
                                    printf("\nDigite o nome do paciente para cadastro: \n");
                                    scanf(" %49[^\n]", espAtual->status.nomepacientetarde[vagaEncontrada]);
                                    printf("\nDigite seu CPF: \n");
                                    scanf(" %11s", espAtual->status.cpfpacientetarde[vagaEncontrada]);

                                    printf("\nAgendamento confirmado (Tarde) para o paciente %s na especialidade %s!\n", 
                                           espAtual->status.nomepacientetarde[vagaEncontrada], espAtual->nomeEspecialidade);
                                } else {
                                    printf("\nDesculpe, todas as 6 vagas da tarde para esta especialidade estao ocupadas!\n");
                                }
                            } else {
                                printf("\nTurno invalido!\n");
                            }
                        } else if (agendarvaga == 2) {
                            printf("\nVoltando ao menu principal...\n");
                        } else {
                            printf("\nOpcao invalida\n");
                        }
                    } while(agendarvaga != 1 && agendarvaga != 2);
                } else {
                    printf("\nOpcao de agencia invalida!\n");
                }
                break;
                
            case 0:
                printf("Encerrando o sistema, ate logo...\n");
                break;
            default:
                printf("\nOpcao invalida!\n");
                break;
        }
    } while(opcao != 0);

    return 0;
}
    
