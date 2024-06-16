/**
 * Balcita, V.
 * Ganituen, Z.
 * Jimenez, J.
 * 
 * CCDSALG, Project 1
 * 
 * Source file of postfix evaluation algorithm.
*/

#include "queue.h"
#include "stack.h"


int Evaluate(int token1,int operator,int token2){
    int result;
    switch(operator){
        case '+': result = token1 + token2; return result; break;
        case '-': result = token1 - token2; return result; break;
        case '*': result = token1 * token2; return result; break;
        case '/': result = token1 / token2; return result; break;
        case '<': result = token1 < token2; return result; break;
        case '>': result = token1 > token2; return result; break;
        case '&': result = token1 && token2; return result; break;
        case '|': result = token1 || token2; return result; break;
        case '=': result = token1 == token2; return result; break;
        case '!': result = token1 != token2; return result; break;
        default: return result; break;
    }
    
}

int EvaluatePostfix(queue Postfix){
stack Output = createStack(Postfix.elems);
queue temporary = createQueue(Postfix.elems);

while(!queueEmpty(Postfix)){

    if(isOperator(queueHead(Postfix))){
        enqueue(pop(&Output),&temporary);
        enqueue(dequeue(&Postfix),&Postfix);
        enqueue(pop(&Output),&temporary);
        push(Evaluate(dequeue(&temporary),dequeue(&temporary),dequeue(&temporary)),&Output);
    }
    else{
        push(dequeue(&Postfix),&Output);
    }
}
return pop(&Output);
}