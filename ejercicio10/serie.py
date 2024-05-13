import multiprocessing

def generar_serie(parametros):
    inicio, fin, paso = parametros
    serie = []
    for i in range(inicio, fin + 1, paso):
        serie.append(i)
    return serie

def procesar_serie(serie):
    res = []
    for num in serie:
        res.append(2 * num)
    return res

if __name__ == '__main__':
    M = 4  # Número de procesadores (vectores)
    N = 10  # Número de términos en la serie
    paso = N // M  

    
    segmentos_serie = [(i * paso + 1, (i + 1) * paso, 1) for i in range(M)]
    if N % M != 0:
        segmentos_serie[-1] = (segmentos_serie[-1][0], segmentos_serie[-1][1] + N % M, 1)

    
    pool = multiprocessing.Pool(processes=M)

    
    serie = pool.map(generar_serie, segmentos_serie)

    
    serie_procesada = pool.map(procesar_serie, serie)

    
    for segmento in serie_procesada:
        for num in segmento:
            print(num, end=" ")
