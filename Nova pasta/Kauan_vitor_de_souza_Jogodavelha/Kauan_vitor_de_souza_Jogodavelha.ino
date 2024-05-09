int Linha;
int Coluna;
bool HaVencedor = false;
int JogadorDaVez = 1;
int Velha = 1;
int j;

//criação do tabuleiro
int tabuleiro[3][3] = {
  { 0, 0, 0 },
  { 0, 0, 0 },
  { 0, 0, 0 }
};
//verificação para ver se a jogada e valida ou invalida
boolean verificarJogada(int Linha, int Coluna) {
  boolean jogadaValida = false;
  if (Linha == 0 || Linha == 1 || Linha == 2) {
    if (Coluna == 0 || Coluna == 1 || Coluna == 2) {
      jogadaValida = true;
    }
  }
  return jogadaValida;
}

void setup() {
  Serial.begin(9600);

  //zera  o tabuleiro
  for (int Linha = 0; Linha <= 2; Linha++) {
    for (int Coluna = 0; Coluna <= 2; Coluna++) {
      tabuleiro[Linha][Coluna] = 0;
    }
  }

  //onde escreve o tabuleiro no serial
  for (int Linha = 0; Linha <= 2; Linha++) {
    if (Linha == 1 | Linha == 2) {
      Serial.println("");
    }
    for (int Coluna = 0; Coluna <= 2; Coluna++) {
      Serial.print(tabuleiro[Linha][Coluna]);
    }
  }
  Serial.println("");
  Serial.print("Digite sua jogada jogador");
  Serial.println(JogadorDaVez);
}


void loop() {
  HaVencedor = false;

  //zera o tabuleiro
  for (int Linha = 0; Linha <= 2; Linha++) {
    for (int Coluna = 0; Coluna <= 2; Coluna++) {
      tabuleiro[Linha][Coluna] = 0;
    }
  }

  //onde escreve o tabuleiro no serial
  for (int Linha = 0; Linha <= 2; Linha++) {
    if (Linha == 1 | Linha == 2) {
      Serial.println("");
    }
    for (int Coluna = 0; Coluna <= 2; Coluna++) {
      Serial.print(tabuleiro[Linha][Coluna]);
    }
  }


  do {
    while (!Serial.available())
      ;

    String entrada = Serial.readString();
    Serial.println("");
    Serial.println(entrada);

    Linha = entrada.substring(0, 1).toInt();
    Coluna = entrada.substring(2, 3).toInt();

    if (verificarJogada(Linha, Coluna) == true) {
      if (tabuleiro[Linha][Coluna] == 0) {
        tabuleiro[Linha][Coluna] = JogadorDaVez;

        //zera a matriz do tabuleiro
        for (int Linha = 0; Linha <= 2; Linha++) {
          if (Linha == 1 || Linha == 2) {
            Serial.println("");
          }
          for (int Coluna = 0; Coluna <= 2; Coluna++) {
            Serial.print(tabuleiro[Linha][Coluna]);
          }
        }

        //verificação de jogadas nas Linhas,Colunas e diagonal para ver se alguem ganhou
        if ((tabuleiro[0][0] == JogadorDaVez && tabuleiro[0][1] == JogadorDaVez && tabuleiro[0][2] == JogadorDaVez) || (tabuleiro[1][0] == JogadorDaVez && tabuleiro[1][1] == JogadorDaVez && tabuleiro[1][2] == JogadorDaVez) || (tabuleiro[2][0] == JogadorDaVez && tabuleiro[2][1] == JogadorDaVez && tabuleiro[2][2] == JogadorDaVez) || (tabuleiro[0][0] == JogadorDaVez && tabuleiro[1][0] == JogadorDaVez && tabuleiro[2][0] == JogadorDaVez) || (tabuleiro[0][1] == JogadorDaVez && tabuleiro[1][1] == JogadorDaVez && tabuleiro[2][1] == JogadorDaVez) || (tabuleiro[0][2] == JogadorDaVez && tabuleiro[1][2] == JogadorDaVez && tabuleiro[2][2] == JogadorDaVez) || (tabuleiro[0][0] == JogadorDaVez && tabuleiro[1][1] == JogadorDaVez && tabuleiro[2][2] == JogadorDaVez) || (tabuleiro[0][2] == JogadorDaVez && tabuleiro[1][1] == JogadorDaVez && tabuleiro[2][0] == JogadorDaVez)) {
          HaVencedor = true;
          j = 1;
        }

        //troca de jogadores
        if (JogadorDaVez == 1 && HaVencedor == false) {
          JogadorDaVez = 2;
        } else if (JogadorDaVez == 2 && HaVencedor == false) {
          JogadorDaVez = 1;
        }

        //contador de jogadas
        Velha = Velha + 1;
        Serial.print("\nContagem jogadas=");
        Serial.println(Velha);
        //Serial.println("");
        Serial.print("Faca sua jogada jogador");
        Serial.println(JogadorDaVez);

        //quando ja foi colocada uma peça no lugar
      } else {
        Serial.println("Posicao ocupada.");
        Serial.print("Jogue novamente jogador");
        Serial.println(JogadorDaVez);
      }
      //quando a jogada não for valida
    } else {
      Serial.println("Jogada invalida.");
      Serial.print("Jogue novamente jogador");
      Serial.println(JogadorDaVez);
    }

    //quando HaVencedor não for diferente e Velha <9 vai voltar  para o (do)
  } while (!HaVencedor && Velha <= 9);
  if (Velha == 9) {
    j = 2;
  }
  switch (j) {
    case 1:
      Serial.print("Voce Venceu ");
      Serial.print(JogadorDaVez);
      Serial.println("");
      Velha = 1;
      break;
    case 2:
      Serial.println("Velha");
      Velha = 1;
      break;
  }
}