
int(String);
double toDouble(String);
int getValArrayInt(int Linha, int coluna, int matriz[], int qtdeLinha);
bool validaPosicao = false;
int velha;
int Linha;
int qtdeLinha;
int coluna;
bool HaVencedor = false;
int tabuleiro[9];
int index;
int JogadorDaVez;
int jogada;
int entrada;
int matriz;
void setup() {
  Serial.begin(115200);
  {
    for (index = 0; index <= 8; index++)
      tabuleiro[index] = 0;
  }

  String jogada;
  // inicio do jogo, decidir quem joga primeiro
  int JogadorDaVez = 1;
  // registrar a jogada do primeiro jogador
  velha = 1;
}

void loop() {
  do {
    Serial.print(tabuleiro[0]);
    Serial.print(tabuleiro[1]);
    Serial.println(tabuleiro[2]);
    Serial.print(tabuleiro[3]);
    Serial.print(tabuleiro[4]);
    Serial.println(tabuleiro[5]);
    Serial.print(tabuleiro[6]);
    Serial.print(tabuleiro[7]);
    Serial.println(tabuleiro[8]);
    //verificação de possivel jogo ganho nas linhas
    jogada = "";
    Serial.print("Digite a posição da peça JOGADOR");
    Serial.println(JogadorDaVez);
    String ler = Serial.readString();
    if (validaPosicao(jogada)) ;

      Linha = int(jogada[0]);
      coluna = int(jogada[2]);
      Serial.print("Linha");
      Serial.print(Linha);
      Serial.print("coluna");
      Serial.print(coluna);
      {

        if (tabuleiro[3 * Linha + coluna] == 0) {
          tabuleiro[3 * Linha + coluna] == JogadorDaVez;
          if (tabuleiro[0] == JogadorDaVez && tabuleiro[1] == JogadorDaVez && tabuleiro[2] == JogadorDaVez && tabuleiro[3] == JogadorDaVez && tabuleiro[4] == JogadorDaVez && tabuleiro[5] == JogadorDaVez && tabuleiro[6] == JogadorDaVez && tabuleiro[7] == JogadorDaVez && tabuleiro[8] == JogadorDaVez && tabuleiro[9]) {
            HaVencedor = true;

          } else {

            if (tabuleiro[0] == JogadorDaVez && tabuleiro[3] == JogadorDaVez && tabuleiro[6] == JogadorDaVez && tabuleiro[1] == JogadorDaVez && tabuleiro[4] == JogadorDaVez && tabuleiro[7] == JogadorDaVez && tabuleiro[2] == JogadorDaVez && tabuleiro[5] == JogadorDaVez && tabuleiro[8]) {
              HaVencedor = true;

            } else {

              if (tabuleiro[0] == JogadorDaVez && tabuleiro[4] == JogadorDaVez && tabuleiro[8] == JogadorDaVez && tabuleiro[2] == JogadorDaVez && tabuleiro[4] == JogadorDaVez && tabuleiro[6]) {
                HaVencedor = true;

              } else {

                //trocar de jogador
                if (JogadorDaVez == 1)

                  (JogadorDaVez == 2);
              }else {
                JogadorDaVez = 1;
              }
            }
          }
        velha = velha + 1;
      }else {

        Serial.print("Posição ocupada, jogue novamente");
        {
          Serial.println
          // avisar que a posição ja foi jogada (ocupada) a jogada do jogador sera invalida
        }

        Serial.print("Jogada invalida !");
        {
          Serial.println
        }
      }
      while (HaVencedor && velha <= 9)
        ;


      // verificação do tabuleiro para ver se alguem ganhou, perdeu ou empatou para encerrar a partida
      if (HaVencedor) {
        Serial.print("Parabens pela vitoria, jogador & JogadorDaVez");
        Serial.println(JogadorDaVez);
      } else {
        Serial.print("Deu velha");
      }

      int getValArray(int Linha, int coluna, int matriz[], qtdeLinha);

      valor = matriz[qtdeLinha * Linha & coluna];
      int entradavalida = false;
      Serial.println(entrada.length());
      if (entrada.length() == 3) {
        Serial.print("comprimento da string igual 3");
        if (entrada[0] == '0' || entrada[0] == '1' || entrada[0] == '2') {
          Serial.println(entrada[0]);
          if (entrada[2] == '0' || entrada[2] == '1' || entrada[2] == '2') {
            Serial.println(entrada[2]);
            entradavalida = true;
          }
        }
      }
    }
