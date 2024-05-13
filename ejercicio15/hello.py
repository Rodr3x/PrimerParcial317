from multiprocessing import Process, current_process

def hola_mundo(numero_proceso, total_procesos):
    print(f"Proceso {numero_proceso} de {total_procesos}: Hola Mundo desde PYTHON!")

if name == '__main__':
    procesos = []
    total_procesos = 4

    for numero_proceso in range(total_procesos):
        proceso = Process(target=hola_mundo, args=(numero_proceso, total_procesos))
        procesos.append(proceso)
        proceso.start()

    for proceso in procesos:
        proceso.join()