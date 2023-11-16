/*

Problemas de Escopo com #define:

Quando você usa #define para criar constantes simbólicas, não há escopo associado a esses símbolos. Eles são substituídos diretamente pelo pré-processador antes da compilação. Isso significa que, se você tiver múltiplos blocos de código ou arquivos fonte, a constante simbólica definida por #define estará disponível em todo o escopo, o que pode levar a colisões de nomes e bugs difíceis de rastrear.
*/


// Exemplo:

#define pinLed 12

void funcaoA() {
    // código que usa pinLed
}

void funcaoB() {
    // código que usa pinLed, mas pode não estar claro
    // que está relacionado ao mesmo pinLed usado em funcaoA
}

/* 
Verificações de Tipo com const:

Quando você declara uma variável como const int, 
o compilador faz verificações de tipo durante a 
compilação para garantir que você não esteja tentando modificar o valor 
dessa variável inadvertidamente. Se você tentar atribuir um 
novo valor a uma variável const, o compilador emitirá um erro.

*/

// Exemplo:

const int pinLed = 12;
pinLed = 13; // Isso resultará em um erro de compilação

/* 
    Esse comportamento ajuda a evitar erros durante o desenvolvimento, 
    pois o compilador sinaliza potenciais problemas de modificação de variáveis constantes.

*/