#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv('alturas.csv')
df.columns = [i.strip() for i in df.columns]

df = df[df['teste'] <= 3]
grupos = df.groupby('teste')

nplot = 1
plt.figure(figsize=(10, 10), dpi = 300)

# Configuração de espaços
plt.subplots_adjust(
    hspace = 0.6    
)

for g in grupos.groups:
    ax = plt.subplot(5, 1, nplot)
    gdados = grupos.get_group(g)
    
    n_teste = gdados['teste'].unique().astype(str)[0]

    gdados[['altura', 'log2n']].plot(ax = ax, legend = False)
    plt.title(f'Teste n° {n_teste}')
    nplot += 1
