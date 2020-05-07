#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv('alturas.csv')
df.columns = [i.strip() for i in df.columns]

# Utilizando apenas os três primeiros testes
df = df[df['teste'] <= 3]
grupos = df.groupby('teste')

nplot = 1
fig = plt.figure(figsize=(10, 10), dpi = 300)

# Configuração de espaços
plt.subplots_adjust(
    hspace = 0.6    
)

for g in grupos.groups:
    ax = plt.subplot(5, 1, nplot)
    gdados = grupos.get_group(g)
    gdados.index = [1, 2, 3, 4, 5, 6]
    
    if nplot == 2:
        plt.ylabel('Altura', fontsize = 14)
    n_teste = gdados['teste'].unique().astype(str)[0]
    plt.xticks([])

    gdados[['altura', 'log2n']].plot(ax = ax, legend = False)
    plt.title(f'Teste n° {n_teste}')
    nplot += 1
plt.legend(['Altura gerada', 'Altura ideal ($Log_2{n}$)'])
plt.tight_layout()
plt.xticks([0, 1, 2, 3, 4, 5])
plt.xlabel('N', fontsize = 14)
plt.savefig('avaliacao.png', dpi=fig.dpi)
