using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Calculo
{
    public class Infija
    {
        public static int Evaluar(string postfija)
        {
            Stack<int> pila = new Stack<int>();

            foreach (string token in postfija.Split(' '))
            {
                //MessageBox.Show(token);
                if (int.TryParse(token, out int numero))
                {
                    pila.Push(numero);
                }
                else
                {
                    if (pila.Count < 2)
                    {
                        throw new InvalidOperationException("Expresión mal formada.");
                    }

                    int b = pila.Pop();
                    int a = pila.Pop();

                    switch (token)
                    {
                        case "+": pila.Push(a + b); break;
                        case "-": pila.Push(a - b); break;
                        case "*": pila.Push(a * b); break;
                        case "/":
                            if (b == 0)
                                throw new DivideByZeroException("División por cero no permitida.");
                            pila.Push(a / b);
                            break;
                        default:
                            throw new ArgumentException($"Operador desconocido: {token}");
                    }
                }
            }

            if (pila.Count != 1)
            {
                throw new InvalidOperationException("La expresión no se pudo evaluar correctamente.");
            }

            return pila.Pop();
        }
    }
}
