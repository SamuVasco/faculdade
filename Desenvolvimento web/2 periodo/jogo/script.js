// =========================================================================
// 1. ESTADO GLOBAL DO JOGO E CONFIGURAÇÕES
// =========================================================================
let jogoAtivo = true;
let tempo = 60;
let vidas = 10;
const maxVidas = 10;
let contadorSegundosDrenagem = 0;

// Configurações do Personagem
let posicaoX = 500;          
let posicaoY = 62;           
const alturaSolo = 62;
let velocidadeY = 0;
const gravidade = 1.1;
let noChao = true;
const teclasPressionadas = {};

// Configurações do Obstáculo
let posicaoObstaculoX = 0;
let direcaoObstaculo = 1;

// Configurações do Item de Vida
let ladoAtualItem = 'esquerda'; 
let posicaoItemX = 80;
let posicaoItemY = 84;
let itemAtivo = true;

// =========================================================================
// 2. REFERÊNCIAS DOS ELEMENTOS HTML (DOM)
// =========================================================================
const elementoTempo = document.getElementById('tempo');
const elementoVidas = document.getElementById('qtd-vidas');
const personagem = document.querySelector('.personagem');
const obstaculo = document.querySelector('.obstaculo');
const itemVida = document.querySelector('.item-vida') || document.getElementById('vida1');


// =========================================================================
// 3. MECÂNICAS CENTRAIS (TEMPO E VIDA)
// =========================================================================

// Função responsável por adicionar ou remover vidas
function alterarVidas(quantidade) {
    vidas += quantidade;

    // Limites de vida
    if (vidas > maxVidas) vidas = maxVidas;
    if (vidas < 0) vidas = 0;

    if (elementoVidas) {
        elementoVidas.textContent = vidas;
    }

    if (vidas <= 0) {
        executarGameOver("Suas vidas acabaram!");
    }
}

// Loop Principal de Tempo (roda a cada 1 segundo)
const temporizador = setInterval(() => {
    if (!jogoAtivo) return;

    tempo--;
    if (elementoTempo) {
        elementoTempo.textContent = tempo;
    }

    // Regra: Perde 1 vida a cada 2 segundos
    contadorSegundosDrenagem++;
    if (contadorSegundosDrenagem >= 2) {
        alterarVidas(-1);
        contadorSegundosDrenagem = 0;
    }

    // Condição de Vitória
    if (tempo <= 0) {
        tempo = 0;
        executarVitoria();
    }
}, 1000);


// =========================================================================
// 4. LÓGICA DO PERSONAGEM (CONTROLES E FÍSICA)
// =========================================================================

// Captura de Teclas
document.addEventListener('keydown', (event) => {
    teclasPressionadas[event.key] = true;

    if (event.key === 'ArrowUp' && noChao && jogoAtivo) {
        velocidadeY = 12; // Impulso do pulo
        noChao = false;
    }
});

document.addEventListener('keyup', (event) => {
    teclasPressionadas[event.key] = false;
});

// Loop de Movimentação do Personagem (~60 FPS)
const loopPersonagem = setInterval(() => {
    if (!jogoAtivo) return;

    const limiteDireito = window.innerWidth - 100;
    const tempoDecorrido = 60 - tempo;
    const velocidadePersonagem = 4 + (tempoDecorrido * 0.06);

    // Movimento Horizontal
    if (teclasPressionadas['ArrowRight'] && posicaoX < limiteDireito) {
        posicaoX += velocidadePersonagem;
    }
    if (teclasPressionadas['ArrowLeft'] && posicaoX > 0) {
        posicaoX -= velocidadePersonagem;
    }

    // Aplicação da Gravidade
    if (!noChao) {
        posicaoY += velocidadeY;    
        velocidadeY -= gravidade;   

        // Checagem se tocou no chão
        if (posicaoY <= alturaSolo) {
            posicaoY = alturaSolo;
            velocidadeY = 0;
            noChao = true;
        }
    }

    // Renderização visual
    personagem.style.left = `${posicaoX}px`;
    personagem.style.bottom = `${posicaoY}px`;
}, 1000 / 60); 


// =========================================================================
// 5. LÓGICA DO OBSTÁCULO (BOLA) E COLISÕES
// =========================================================================

const loopObstaculo = setInterval(() => {
    if (!jogoAtivo) return;

    const tempoDecorrido = 60 - tempo;
    const velocidadeObstaculo = 4 + (tempoDecorrido * 0.21);

    posicaoObstaculoX += velocidadeObstaculo * direcaoObstaculo;

    // Bate e volta nas bordas
    const limiteDireito = window.innerWidth - 40;
    if (posicaoObstaculoX >= limiteDireito) {
        direcaoObstaculo = -1; 
    } else if (posicaoObstaculoX <= 0) {
        direcaoObstaculo = 1;  
    }

    obstaculo.style.left = `${posicaoObstaculoX}px`;

    // A cada passo do obstáculo, checa colisão com o jogador
    checarColisaoObstaculo();
}, 20);

function checarColisaoObstaculo() {
    const rectPersonagem = personagem.getBoundingClientRect();
    const rectObstaculo = obstaculo.getBoundingClientRect();

    const margemEsquerda = 38; 
    const margemDireita = 38;  
    const margemTopo = 20;     
    const margemBase = 25;     
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


// =========================================================================
// 6. LÓGICA DO ITEM DE VIDA (COLETÁVEIS)
// =========================================================================

function gerarAlturaAleatoria(min, max) {
    return Math.floor(Math.random() * (max - min + 1)) + min;
}

function spawnarProximaVida() {
    ladoAtualItem = (ladoAtualItem === 'esquerda') ? 'direita' : 'esquerda';
    posicaoItemX = (ladoAtualItem === 'esquerda') ? 80 : window.innerWidth - 120;
    posicaoItemY = gerarAlturaAleatoria(84, 190);

    if (itemVida) {
        itemVida.style.left = `${posicaoItemX}px`;
        itemVida.style.bottom = `${posicaoItemY}px`;
        itemVida.style.display = 'block';
    }
    itemAtivo = true;
}

function iniciarItemVida() {
    if (!itemVida) return;
    posicaoItemY = gerarAlturaAleatoria(84, 190);
    itemVida.style.left = `${posicaoItemX}px`;
    itemVida.style.bottom = `${posicaoItemY}px`;
    itemVida.style.display = 'block';
}

iniciarItemVida();

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
        alterarVidas(1); 
        itemAtivo = false;
        itemVida.style.display = 'none'; 
        spawnarProximaVida();
    }
}, 20);


// =========================================================================
// 7. GESTÃO DE ESTADOS FINAIS (GAME OVER E VITÓRIA)
// =========================================================================

function pararTodosOsLoops() {
    jogoAtivo = false;
    clearInterval(temporizador);
    clearInterval(loopObstaculo);
    clearInterval(loopChecarVida);
    clearInterval(loopPersonagem);
}

function executarGameOver(motivo) {
    pararTodosOsLoops();

    const telaGameOver = document.getElementById('game-over-screen');
    if (telaGameOver) {
        telaGameOver.style.display = 'flex';
    }
    console.log(`GAME OVER! Motivo: ${motivo}`);
}

function executarVitoria() {
    pararTodosOsLoops();

    const telaVitoria = document.getElementById('vitoria-screen');
    if (telaVitoria) {
        telaVitoria.style.display = 'flex';
    }
    console.log("PARABÉNS! Você sobreviveu aos 60 segundos!");
}

function reiniciarJogo() {
    window.location.reload();
}