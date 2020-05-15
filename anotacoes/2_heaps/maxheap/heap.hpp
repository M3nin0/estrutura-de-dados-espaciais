#ifndef _HEAP_HEADER
#define _HEAP_HEADER

#include <cstddef>
#include <vector>
#include <iostream>

template <class T>
class MaxHeap
{
public:
    MaxHeap(const std::vector<T>& vec);

    std::vector<T> ExtractHeap(std::size_t n);

    std::size_t Begin() const;
    std::size_t End() const;
private:
    std::vector<T> p_vec;

    void FixUpHeap(T elm, std::size_t i);
    void FixDownHeap(std::size_t limitToRemove, std::size_t actualPosition);
};

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

    for(std::size_t i = 0; i < limitToRemove; ++i)
    {
        sortedElements.push_back(p_vec[0]); // max-heap(raiz = valor máximo)
        p_vec[0] = p_vec[limitToRemove - i]; // a raiz passa a ser o último elemento da sequência
        
        FixDownHeap(limitToRemove, 0);
        p_vec[limitToRemove - i] = -1; // adicionado para o entendimento da operação de remoção
                                       // onde cada elemento '-1' representa uma posição removida
    }

    return sortedElements;
}

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
        if ((j < limitToRemove) && (p_vec[j] < p_vec[j + 1]))
            ++j; // se eu estou dentro do range definido para remoção
                // e, descubro que o filho direito é maior que o esquerdo
                // somo +1 ao j para, nas linhas abaixo trabalhar com o elemento à direita,
                // caso contrário, o elemento trabalhado permanece sendo o esquerdo.

        if (v > p_vec[j]) // se a posição onde estou é maior que meu maior filho
                          // cheguei no ponto em que queria, assim, posso parar a 'varredura'
            break;
        p_vec[j / 2] = p_vec[j]; // caso o filho seja maior, então, o valor do pai é trocado pelo
                                 // seu filho.
        j *= 2; // passa para a próxima raiz
    }
    p_vec[j / 2] = v;
}

#endif
