// ==========================================
// 1. TIMER E VARIÁVEIS GLOBAIS
// ==========================================
var tempo = 60;
const elementoTempo = document.getElementById('tempo');

let vidas = 10;
const maxVidas = 10;
const elementoVidas = document.getElementById('qtd-vidas');

let contadorSegundosDrenagem = 0; // Controle para drenar vidas a cada 2s
let jogoAtivo = true;

// TIMER PRINCIPAL (Diminui o tempo e drena 1 vida a cada 2 segundos)
const temporizador = setInterval(() => {
    if (!jogoAtivo) return;

    tempo--;
    if (elementoTempo) {
        elementoTempo.textContent = tempo;
    }

    // REGRA DE DRENAGEM: Perde 1 vida a cada 2 segundos
    contadorSegundosDrenagem++;
    if (contadorSegundosDrenagem >= 2) {
        alterarVidas(-1);
        contadorSegundosDrenagem = 0;
    }

    // CONDICIONAL DE VITÓRIA: Sobreviveu aos 60 segundos!
    if (tempo <= 0) {
        tempo = 0;
        executarVitoria(); // <-- Chama a tela de vitória
    }
}, 1000);

// FUNÇÃO PARA ATUALIZAR E VALIDAR VIDAS
function alterarVidas(quantidade) {
    vidas += quantidade;

    // Limita o máximo a 10 e o mínimo a 0
    if (vidas > maxVidas) vidas = maxVidas;
    if (vidas < 0) vidas = 0;

    if (elementoVidas) {
        elementoVidas.textContent = vidas;
    }

    // Se as vidas acabarem, dispara Game Over
    if (vidas <= 0) {
        executarGameOver("Suas vidas acabaram!");
    }
}


// ==========================================
// 2. PERSONAGEM (COM MOVIMENTO NO AR E GRAVIDADE)
// ==========================================
const personagem = document.querySelector('.personagem');

let posicaoX = 500;          
let posicaoY = 62;           
const alturaSolo = 62;

// Física do pulo
let velocidadeY = 0;
const gravidade = 1.1;
let noChao = true;

// Estado das teclas pressionadas (permite mover no ar suavemente)
const teclasPressionadas = {};

document.addEventListener('keydown', (event) => {
    teclasPressionadas[event.key] = true;

    // PULAR (Só pode iniciar o pulo se estiver no chão)
    if (event.key === 'ArrowUp' && noChao && jogoAtivo) {
        velocidadeY = 12; // Impulso inicial do pulo
        noChao = false;
    }
});

document.addEventListener('keyup', (event) => {
    teclasPressionadas[event.key] = false;
});

// Loop principal de movimentação e física do personagem (60 FPS)
const loopPersonagem = setInterval(() => {
    if (!jogoAtivo) return;

    const limiteDireito = window.innerWidth - 100;

    // VELOCIDADE DINÂMICA
    const tempoDecorrido = 60 - tempo;
    const velocidadePersonagem = 4 + (tempoDecorrido * 0.06);

    // MOVIMENTO HORIZONTAL (Funciona no chão e no ar!)
    if (teclasPressionadas['ArrowRight']) {
        if (posicaoX < limiteDireito) {
            posicaoX += velocidadePersonagem;
        }
    }
    if (teclasPressionadas['ArrowLeft']) {
        if (posicaoX > 0) {
            posicaoX -= velocidadePersonagem;
        }
    }

    // APLICAÇÃO DA GRAVIDADE E PULO
    if (!noChao) {
        posicaoY += velocidadeY;    // Sobe ou desce de acordo com a velocidade
        velocidadeY -= gravidade;   // Gravidade puxa para baixo a cada frame

        // Tocou no chão
        if (posicaoY <= alturaSolo) {
            posicaoY = alturaSolo;
            velocidadeY = 0;
            noChao = true;
        }
    }

    // Atualiza a posição visual no DOM
    personagem.style.left = `${posicaoX}px`;
    personagem.style.bottom = `${posicaoY}px`;
}, 1000 / 60); // Corre a ~60 FPS


// ==========================================
// 3. OBSTÁCULO (BOLA)
// ==========================================
const obstaculo = document.querySelector('.obstaculo');
let posicaoObstaculoX = 0;
let direcaoObstaculo = 1;

// Loop de movimentação e colisão do obstáculo (roda a cada 20ms)
const loopObstaculo = setInterval(() => {
    if (!jogoAtivo) return;

    // VELOCIDADE DINÂMICA DA BOLA:
    // Começa com velocidade 3 e ganha +0.20 a cada segundo que passa
    const tempoDecorrido = 60 - tempo;
    const velocidadeObstaculo = 4 + (tempoDecorrido * 0.21);

    // Mover o obstáculo
    posicaoObstaculoX += velocidadeObstaculo * direcaoObstaculo;

    // Rebater nas bordas da tela
    const limiteDireito = window.innerWidth - 40;
    if (posicaoObstaculoX >= limiteDireito) {
        direcaoObstaculo = -1; // Muda direção para a esquerda
    } else if (posicaoObstaculoX <= 0) {
        direcaoObstaculo = 1;  // Muda direção para a direita
    }

    // Atualiza posição no CSS
    obstaculo.style.left = `${posicaoObstaculoX}px`;

    // VERIFICAR COLISÃO COM O PERSONAGEM
    checarColisao();
}, 20);

function checarColisao() {
    const rectPersonagem = personagem.getBoundingClientRect();
    const rectObstaculo = obstaculo.getBoundingClientRect();

    // Margens ajustadas:
    // Aumentamos a margem da esquerda (mãozinha) e a margem inferior (para não bater no ar)
    const margemEsquerda = 38; // Protege a ponta da mão esquerda
    const margemDireita = 38;  // Protege a lateral direita
    const margemTopo = 20;     // Topo da cabeça
    const margemBase = 25;     // SUBIU A BASE: evita colisão falsa com o obstáculo no chão!

    // Redução do contorno da bola vermelha
    const margemObstaculo = 4;

    const corpoPersonagem = {
        left: rectPersonagem.left + margemEsquerda,
        right: rectPersonagem.right - margemDireita,
        top: rectPersonagem.top + margemTopo,
        bottom: rectPersonagem.bottom - margemBase
    };

    const corpoObstaculo = {
        left: rectObstaculo.left + margemObstaculo,
        right: rectObstaculo.right - margemObstaculo,
        top: rectObstaculo.top + margemObstaculo,
        bottom: rectObstaculo.bottom - margemObstaculo
    };

    const colidiu = !(
        corpoPersonagem.right < corpoObstaculo.left ||
        corpoPersonagem.left > corpoObstaculo.right ||
        corpoPersonagem.bottom < corpoObstaculo.top ||
        corpoPersonagem.top > corpoObstaculo.bottom
    );

    if (colidiu) {
        executarGameOver("Colisão com o obstáculo!");
    }
}


// ==========================================
// 4. ITEM DE VIDA (ÚNICO NA TELA)
// ==========================================
const itemVida = document.querySelector('.item-vida') || document.getElementById('vida1');

let ladoAtualItem = 'esquerda'; 
let posicaoItemX = 80;
let posicaoItemY = 84;
let itemAtivo = true;

function gerarAlturaAleatoria(min, max) {
    return Math.floor(Math.random() * (max - min + 1)) + min;
}

function spawnarProximaVida() {
    // Alterna de lado: se era esquerda vai pra direita, e vice-versa
    ladoAtualItem = (ladoAtualItem === 'esquerda') ? 'direita' : 'esquerda';

    if (ladoAtualItem === 'esquerda') {
        posicaoItemX = 80;
    } else {
        posicaoItemX = window.innerWidth - 120;
    }

    // Calcula altura aleatória entre 84px e 190px
    posicaoItemY = gerarAlturaAleatoria(84, 190);

    if (itemVida) {
        itemVida.style.left = `${posicaoItemX}px`;
        itemVida.style.bottom = `${posicaoItemY}px`;
        itemVida.style.display = 'block';
    }
    itemAtivo = true;
}

// Inicializa a primeira vida assim que o jogo arranca
function iniciarItemVida() {
    if (!itemVida) return;
    posicaoItemY = gerarAlturaAleatoria(84, 190);
    itemVida.style.left = `${posicaoItemX}px`;
    itemVida.style.bottom = `${posicaoItemY}px`;
    itemVida.style.display = 'block';
}

iniciarItemVida();

// Loop para checar colisão com o item de vida
const loopChecarVida = setInterval(() => {
    if (!jogoAtivo || !itemAtivo || !itemVida) return;

    const rectPersonagem = personagem.getBoundingClientRect();
    const rectItem = itemVida.getBoundingClientRect();

    const margemHorizontal = 35;
    const margemVertical = 15;

    const corpoPersonagem = {
        left: rectPersonagem.left + margemHorizontal,
        right: rectPersonagem.right - margemHorizontal,
        top: rectPersonagem.top + margemVertical,
        bottom: rectPersonagem.bottom - margemVertical
    };

    const coletou = !(
        corpoPersonagem.right < rectItem.left ||
        corpoPersonagem.left > rectItem.right ||
        corpoPersonagem.bottom < rectItem.top ||
        corpoPersonagem.top > rectItem.bottom
    );

    if (coletou) {
        alterarVidas(1); // Ganha +1 vida
        itemAtivo = false;
        itemVida.style.display = 'none'; // Sumir imediatamente

        // Surge do outro lado da tela com nova altura
        spawnarProximaVida();
    }
}, 20);


// ==========================================
// 5. GAME OVER
// ==========================================
function executarGameOver(motivo) {
    jogoAtivo = false;
    
    // Interrompe todos os loops ativos do jogo
    clearInterval(temporizador);
    clearInterval(loopObstaculo);
    clearInterval(loopChecarVida);
    clearInterval(loopPersonagem);

    // Exibe a tela com a imagem de Game Over
    const telaGameOver = document.getElementById('game-over-screen');
    if (telaGameOver) {
        telaGameOver.style.display = 'flex';
    }

    console.log(`GAME OVER! Motivo: ${motivo}`);
}

// ==========================================
// 6. VITÓRIA (SOBREVIVEU 60s)
// ==========================================
function executarVitoria() {
    jogoAtivo = false;

    // Interrompe todos os loops ativos do jogo
    clearInterval(temporizador);
    clearInterval(loopObstaculo);
    clearInterval(loopChecarVida);
    clearInterval(loopPersonagem);

    // Exibe a tela com a imagem de Vitória
    const telaVitoria = document.getElementById('vitoria-screen');
    if (telaVitoria) {
        telaVitoria.style.display = 'flex';
    }

    console.log("PARABÉNS! Você sobreviveu aos 60 segundos!");
}

// ==========================================
// 7. REINICIAR JOGO
// ==========================================
function reiniciarJogo() {
    // Recarrega a página para reiniciar todos os timers, variáveis e posições do zero
    window.location.reload();
}