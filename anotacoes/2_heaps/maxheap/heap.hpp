#ifndef _HEAP_HEADER
#define _HEAP_HEADER

#include <cstddef>
#include <vector>
#include <iostream>

template <class T>
class MaxHeap
{
public:
    MaxHeap();
    MaxHeap(const std::vector<T>& vec);

    void Sort(std::vector<T>& vec);
    std::vector<T> ExtractHeap(std::size_t n);

    std::size_t Begin() const;
    std::size_t End() const;
private:
    std::vector<T> p_vec;

    void FixUpHeap(T elm, std::size_t i);
    void swap(std::vector<T>& vec1, std::size_t pos1, std::size_t pos2);
    void FixDownHeap(std::size_t limitToRemove, std::size_t actualPosition);
};

template <class T>
MaxHeap<T>::MaxHeap()
{
}

/**
 * Método para a criação de um heap através de um array
 */
template <class T>
MaxHeap<T>::MaxHeap(const std::vector<T>& vec)
{
    p_vec = vec;

    for(std::size_t i = 0; i < vec.size(); ++i)
    {
        FixUpHeap(vec.at(i), i);
    }
}

template <class T>
std::size_t MaxHeap<T>::Begin() const
{
    return 0;
}

template <class T>
std::size_t MaxHeap<T>::End() const
{
    return p_vec.size();
}

/**
 * FixUpHeap garante que as propriedades do heap serão mantidas. 
 * Para isso o código vai empurrando os elementos para baixo, garantindo
 * a propriedade das raizes serem maiores que seus filhos.
 */
template <class T>
void MaxHeap<T>::FixUpHeap(T elm, std::size_t i)
{
    // Enquanto não chegar na raiz (i > 0) e o elemento pai (p_vec[i / 2])
    // for menor que o inserido (el) realiza:
    while ((i > 0) && (p_vec[i / 2] < elm))
    {
        // filho passa a ter valor de pai
        p_vec[i] = p_vec[i / 2];
        i = i / 2;
    }
    p_vec[i] = elm;
}

/**
 *  Devolve os elementos até a posição indicada, em ordem crescente
 */
template <class T>
std::vector<T> MaxHeap<T>::ExtractHeap(std::size_t limitToRemove)
{
    std::vector<T> sortedElements;

    for(std::size_t i = 1; i <= limitToRemove; ++i)
    {
        sortedElements.push_back(p_vec[0]); // max-heap(raiz = valor máximo)
        p_vec[0] = p_vec[limitToRemove - i]; // a raiz passa a ser o último elemento da sequência
        
        FixDownHeap(limitToRemove, 0);
        p_vec[limitToRemove - i] = -1; // adicionado para o entendimento da operação de remoção
                                       // onde cada elemento '-1' representa uma posição removida
    }

    return sortedElements; // em ordem inversa
}

/**
 * Algoritmo que trata de reorganizar o Heap quando o maior elemento é removido.
 * Neste, a substituição entre a raiz e o topo é feita em seguida, o elemento que 
 * está no topo é empurrado para baixo até que esteja na sua posição correta 
 * (Quando não é menor que nínguem)
 */
template <class T>
void MaxHeap<T>::FixDownHeap(std::size_t limitToRemove, std::size_t actualPosition)
{
    T v = p_vec[actualPosition];
    std::size_t j = 1; // filho esquerdo
                       // logo, p_vec[j + 1] = filho direito
                       // Isso pode ser feito já que a operação sempre está sendo
                       // realizada no 'topo' (ou raiz)

    while (j <= limitToRemove)
    {
        // A pergunta respondida na linha abaixo é: Qual dos dois possuí chave maior ?
        if ((j < limitToRemove) && (p_vec[j] < p_vec[j + 1]))
            ++j; // se eu estou dentro do range definido para remoção
                // e, descubro que o filho direito é maior que o esquerdo
                // somo +1 ao j para, nas linhas abaixo trabalhar com o elemento à direita,
                // caso contrário, o elemento trabalhado permanece sendo o esquerdo.

        // A pergunta respondida na linha abaixo é: 
        // O elemento que está no topo é maior do que seu maior filho ?
        if (v > p_vec[j]) // se a posição onde estou é maior que meu maior filho
                          // cheguei no ponto em que queria, assim, posso parar a 'varredura'
            break;
        p_vec[j / 2] = p_vec[j]; // caso o filho seja maior, então, o valor do pai é trocado pelo
                                 // seu filho.
        j *= 2; // passa para a próxima raiz
    }
    p_vec[j / 2] = v; // o pai da posição onde eu estou passa a ser
                      // o valor de 'v'.
}

template <class T>
void MaxHeap<T>::Sort(std::vector<T>& vec)
{
    // inserindo vetor para a ordenação
    // vec.size() = n operações
    p_vec = vec;
    for(std::size_t i = 0; i < vec.size(); ++i)
    {
        FixUpHeap(p_vec.at(i), i);
    }

    // Fazendo o caminho inverso do feito no método "FixDownHeap"
    // Posso fazer isso já que meu método consegue trabalhar com a posição
    // de onde eu considero uma raiz. O que fiz aqui foi 'inverter' a árvore,
    // ou melhor dizendo, inverti a ordem com que leio a árvore.
    for(std::size_t i = vec.size() - 1; i > 0; --i)
    {
        swap(p_vec, 0, i);
        FixDownHeap(i - 1, 0);
    }

    vec = p_vec;
}

template <class T>
void MaxHeap<T>::swap(std::vector<T>& vec1, std::size_t pos1, std::size_t pos2)
{
    T tmp = vec1.at(pos1);
    vec1[pos1] = vec1[pos2];
    vec1[pos2] = tmp;
}

#endif
