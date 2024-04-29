function main() {
    // criar o tabuleiro e os jogadores,zerar as variáveis
    // 
    // 0: Posição vazia
    // 1: Jogada ou posição do jogador1
    // 2: Jogada ou posição do jogador2
    var velha;
    var linha;
    var coluna;
    var jogadordavez;

    jogadordavez = 1;
    var haVencedor;

    haVencedor = false;
    var i;
    var tabuleiro = createArray(9);

    // limpar tabuleiro ou zerar o tabuleiro
    for (i = 0; i <= 8; i++) {
        tabuleiro[i] = 0;
    }
    var jogador1;

    jogador1 = "jogador1";
    var jogador2;

    jogador2 = "jogador2";
    var jogada;

    velha = 1;
    do {
       console.log(tabuleiro[0].toString() + tabuleiro[1] + tabuleiro[2]);
       console.log(tabuleiro[3].toString() + tabuleiro[4] + tabuleiro[5]);
       console.log(tabuleiro[6].toString() + tabuleiro[7] + tabuleiro[8]);
        jogada = "";
       console.log("Digite a posição da peça Jogador " + jogadordavez);
        jogada = window.prompt('Enter a value for jogada');
        linha = parseInt(jogada.charAt(0));
        coluna = parseInt(jogada.charAt(2));
       console.log("Linha" + linha + "; Coluna:" + coluna);

        // verificar se a posição for valida
        // converter a jogada texto em dois inteiros linha e coluna
        if (tabuleiro[3 * linha + coluna] == 0) {
            tabuleiro[3 * linha + coluna] = jogadordavez;

            // se houver ganhador ou empate, finalizar o jogo
            if (tabuleiro[0] == jogadordavez && tabuleiro[1] == jogadordavez && tabuleiro[2] == jogadordavez || tabuleiro[3] == jogadordavez && tabuleiro[4] == jogadordavez && tabuleiro[5] == jogadordavez || tabuleiro[6] == jogadordavez && tabuleiro[7] == jogadordavez && tabuleiro[8] == jogadordavez) {
                haVencedor = true;
            } else {
                if (tabuleiro[0] == jogadordavez && tabuleiro[3] == jogadordavez && tabuleiro[6] == jogadordavez || tabuleiro[1] == jogadordavez && tabuleiro[4] == jogadordavez && tabuleiro[7] == jogadordavez || tabuleiro[2] == jogadordavez && tabuleiro[5] == jogadordavez && tabuleiro[8] == jogadordavez) {
                    haVencedor = true;
                } else {
                    if (tabuleiro[0] == jogadordavez && tabuleiro[4] == jogadordavez && tabuleiro[8] == jogadordavez || tabuleiro[2] == jogadordavez && tabuleiro[4] == jogadordavez && tabuleiro[6] == jogadordavez) {
                        haVencedor = true;
                    } else {
                        if (jogadordavez == 1) {
                            jogadordavez = 2;
                        } else {
                            jogadordavez = 1;
                        }
                    }
                }
            }
            velha = velha + 1;
        } else {
           console.log("posição ocupada jogue novamente !!!");

            // informar ao jogador 1 que a posição esta preenchida e inválida e ele precisa informar uma posição válida
        }
    } while (!haVencedor && velha <= 9);
    if (haVencedor == true) {
       console.log("Jogador" + jogadordavez + " é o vencedor");
    } else {
       console.log("velha");
    }
   console.log(tabuleiro[0].toString() + tabuleiro[1] + tabuleiro[2]);
   console.log(tabuleiro[3].toString() + tabuleiro[4] + tabuleiro[5]);
   console.log(tabuleiro[6].toString() + tabuleiro[7] + tabuleiro[8]);

    // Jogador venceu
}

function validaPosição(entrada) {
    var entradaValida;

    entradaValida = false;
   console.log(entrada.length());
    if (entrada.length() == 3) {
        if (entrada.charAt(0) == "0" || entrada.charAt(0) == "1" || entrada.charAt(0) == "2") {
            if (entrada.charAt(2) == "0" || entrada.charAt(2) == "1" || entrada.charAt(2) == "2") {
                entradaValida = true;
            }
        }
    }
}
