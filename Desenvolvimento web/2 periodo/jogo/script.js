
 // 1. CONFIGURAÇÕES DO JOGO
const DURACAO_JOGO = 60;
const VIDAS_INICIAIS = 10;
const INTERVALO_PERDA_VIDA = 2;

const POSICAO_INICIAL_X = 500;
const ALTURA_SOLO = 62;
const GRAVIDADE = 1.15;
const FORCA_PULO = 11;
const VELOCIDADE_INICIAL_PERSONAGEM = 4;
const AUMENTO_VELOCIDADE_PERSONAGEM = 0.28;
const VELOCIDADE_INICIAL_OBSTACULO = 6;
const AUMENTO_VELOCIDADE_OBSTACULO = 0.5;

const ALTURA_MINIMA_ITEM = 84;
const ALTURA_MAXIMA_ITEM = 190;
const POSICAO_ESQUERDA_ITEM = 80;
const DISTANCIA_DIREITA_ITEM = 120;

const SPRITES = {
    parado: "url('imagens/personagem.webp')",
    direita: "url('imagens/correndo-p-direita.png')",
    esquerda: "url('imagens/correndo-p-esquerda.png')",
    pulando: "url('imagens/pulando.png')"
};

// 2. ELEMENTOS HTML
const elementoTempo = document.getElementById('tempo');
const elementoVidas = document.getElementById('qtd-vidas');
const personagem = document.querySelector('.personagem');
const obstaculo = document.querySelector('.obstaculo');
const itemVida = document.getElementById('vida1');
const telaGameOver = document.getElementById('game-over-screen');
const telaVitoria = document.getElementById('vitoria-screen');

// 3. ESTADO DO JOGO
let jogoAtivo = true;
let tempo = DURACAO_JOGO;
let vidas = VIDAS_INICIAIS;
let segundosDesdePerdaVida = 0;

let posicaoX = POSICAO_INICIAL_X;
let posicaoY = ALTURA_SOLO;
let velocidadeY = 0;
let noChao = true;
let spriteAtual = '';
const teclasPressionadas = {};

let posicaoObstaculoX = 0;
let direcaoObstaculo = 1;
let ladoAtualItem = 'esquerda';

// 4. TEMPO E VIDAS
function alterarVidas(quantidade) {
    vidas = Math.max(0, Math.min(VIDAS_INICIAIS, vidas + quantidade));
    elementoVidas.textContent = vidas;

    if (vidas === 0) {
        executarGameOver('Suas vidas acabaram!');
    }
}

function atualizarTempo() {
    if (!jogoAtivo) return;

    tempo = Math.max(0, tempo - 1);
    elementoTempo.textContent = tempo;

    // A vitória tem prioridade quando o tempo chega a zero.
    if (tempo === 0) {
        executarVitoria();
        return;
    }

    segundosDesdePerdaVida++;
    if (segundosDesdePerdaVida >= INTERVALO_PERDA_VIDA) {
        segundosDesdePerdaVida = 0;
        alterarVidas(-1);
    }
}

// 5. CONTROLES E MOVIMENTAÇÃO DO PERSONAGEM
document.addEventListener('keydown', (event) => {
    if (!jogoAtivo) return;

    if (event.key.startsWith('Arrow')) {
        event.preventDefault();
    }

    teclasPressionadas[event.key] = true;

    if (event.key === 'ArrowUp' && noChao) {
        velocidadeY = FORCA_PULO;
        noChao = false;
    }
});

document.addEventListener('keyup', (event) => {
    teclasPressionadas[event.key] = false;
});

// Evita que o personagem continue andando ao perder o foco da janela.
window.addEventListener('blur', () => {
    teclasPressionadas.ArrowLeft = false;
    teclasPressionadas.ArrowRight = false;
    teclasPressionadas.ArrowUp = false;
});

function atualizarPersonagem() {
    if (!jogoAtivo) return;

    const tempoDecorrido = DURACAO_JOGO - tempo;
    const velocidade = VELOCIDADE_INICIAL_PERSONAGEM +
        tempoDecorrido * AUMENTO_VELOCIDADE_PERSONAGEM;
    const limiteDireito = Math.max(0, window.innerWidth - personagem.offsetWidth);
    let novoSprite = SPRITES.parado;

    if (teclasPressionadas.ArrowRight) {
        posicaoX += velocidade;
        novoSprite = SPRITES.direita;
    } else if (teclasPressionadas.ArrowLeft) {
        posicaoX -= velocidade;
        novoSprite = SPRITES.esquerda;
    }

    posicaoX = Math.max(0, Math.min(limiteDireito, posicaoX));

    if (!noChao) {
        posicaoY += velocidadeY;
        velocidadeY -= GRAVIDADE;
        novoSprite = SPRITES.pulando;

        if (posicaoY <= ALTURA_SOLO) {
            posicaoY = ALTURA_SOLO;
            velocidadeY = 0;
            noChao = true;
        }
    }

    // A imagem só é alterada quando o sprite muda.
    if (spriteAtual !== novoSprite) {
        spriteAtual = novoSprite;
        personagem.style.backgroundImage = novoSprite;
    }

    personagem.style.left = `${posicaoX}px`;
    personagem.style.bottom = `${posicaoY}px`;
}

// 6. COLISÕES E OBSTÁCULO
function obterAreaColisao(elemento, esquerda, direita, topo, base) {
    const rect = elemento.getBoundingClientRect();

    return {
        left: rect.left + esquerda,
        right: rect.right - direita,
        top: rect.top + topo,
        bottom: rect.bottom - base
    };
}

function verificarColisao(a, b) {
    return (
        a.left <= b.right &&
        a.right >= b.left &&
        a.top <= b.bottom &&
        a.bottom >= b.top
    );
}

function checarColisaoObstaculo() {
    // As margens compensam as partes transparentes do sprite.
    const areaPersonagem = obterAreaColisao(personagem, 38, 38, 20, 25);
    const areaObstaculo = obterAreaColisao(obstaculo, 4, 4, 4, 4);

    if (verificarColisao(areaPersonagem, areaObstaculo)) {
        executarGameOver('Colisão com o obstáculo!');
    }
}

function atualizarObstaculo() {
    if (!jogoAtivo) return;

    const tempoDecorrido = DURACAO_JOGO - tempo;
    const velocidade = VELOCIDADE_INICIAL_OBSTACULO +
        tempoDecorrido * AUMENTO_VELOCIDADE_OBSTACULO;
    const limiteDireito = Math.max(0, window.innerWidth - obstaculo.offsetWidth);

    posicaoObstaculoX += velocidade * direcaoObstaculo;

    if (posicaoObstaculoX >= limiteDireito) {
        posicaoObstaculoX = limiteDireito;
        direcaoObstaculo = -1;
    } else if (posicaoObstaculoX <= 0) {
        posicaoObstaculoX = 0;
        direcaoObstaculo = 1;
    }

    obstaculo.style.left = `${posicaoObstaculoX}px`;
    checarColisaoObstaculo();
}

// 7. ITENS DE VIDA
function gerarAlturaAleatoria(min, max) {
    return Math.floor(Math.random() * (max - min + 1)) + min;
}

function posicionarItemVida() {
    itemVida.style.display = 'block';

    const posicaoDesejada = ladoAtualItem === 'esquerda'
        ? POSICAO_ESQUERDA_ITEM
        : window.innerWidth - DISTANCIA_DIREITA_ITEM;
    const limiteDireito = Math.max(0, window.innerWidth - itemVida.offsetWidth);
    const posicaoXItem = Math.max(0, Math.min(limiteDireito, posicaoDesejada));
    const posicaoYItem = gerarAlturaAleatoria(ALTURA_MINIMA_ITEM, ALTURA_MAXIMA_ITEM);

    itemVida.style.left = `${posicaoXItem}px`;
    itemVida.style.bottom = `${posicaoYItem}px`;
}

function checarColetaVida() {
    if (!jogoAtivo) return;

    const areaPersonagem = obterAreaColisao(personagem, 35, 35, 15, 15);
    const areaItem = itemVida.getBoundingClientRect();

    if (verificarColisao(areaPersonagem, areaItem)) {
        alterarVidas(1);
        ladoAtualItem = ladoAtualItem === 'esquerda' ? 'direita' : 'esquerda';
        posicionarItemVida();
    }
}

// 8. ENCERRAMENTO E REINÍCIO
function finalizarJogo(tela, mensagem) {
    if (!jogoAtivo) return;

    jogoAtivo = false;
    clearInterval(temporizador);
    clearInterval(loopPersonagem);
    clearInterval(loopObstaculo);
    clearInterval(loopChecarVida);

    tela.style.display = 'flex';
    console.log(mensagem);
}

function executarGameOver(motivo) {
    finalizarJogo(telaGameOver, `GAME OVER! Motivo: ${motivo}`);
}

function executarVitoria() {
    finalizarJogo(telaVitoria, 'PARABÉNS! Você sobreviveu aos 60 segundos!');
}

function reiniciarJogo() {
    window.location.reload();
}

// 9. INICIALIZAÇÃO DO JOGO
posicaoX = Math.max(0, Math.min(
    posicaoX,
    window.innerWidth - personagem.offsetWidth
));
personagem.style.left = `${posicaoX}px`;
posicionarItemVida();

document.querySelectorAll('.btn-reiniciar').forEach((botao) => {
    botao.addEventListener('click', reiniciarJogo);
});

const temporizador = setInterval(atualizarTempo, 1000);
const loopPersonagem = setInterval(atualizarPersonagem, 1000 / 60);
const loopObstaculo = setInterval(atualizarObstaculo, 20);
const loopChecarVida = setInterval(checarColetaVida, 20);
