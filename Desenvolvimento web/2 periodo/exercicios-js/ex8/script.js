const n1Span = document.getElementById('n1');
const n2Span = document.getElementById('n2');
const n3Span = document.getElementById('n3');
const n4Span = document.getElementById('n4');

function gerar() {
    n1Span.textContent = `${Math.random().toFixed(2)}` 
    n2Span.textContent = `${(Math.random() * 5).toFixed(2)}`
    n3Span.textContent = `${(Math.random() + 2).toFixed(2)}`
    n4Span.textContent = `${Math.floor((Math.random() * 8 + 5))}`
}
 