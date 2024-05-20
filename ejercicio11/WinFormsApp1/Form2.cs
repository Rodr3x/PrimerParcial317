using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Collections.Generic;
using Calculo;


namespace WinFormsApp1
{
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Button boton = sender as Button;
            if (boton != null)
            {
                
                if (resultado == 0 && char.IsDigit(boton.Text, 0))
                    textBox1.Clear();

                textBox1.Text += boton.Text + " ";
            }
        }

        public int resultado = 2;
        public Boolean flag = false;

        private void button15_Click(object sender, EventArgs e)
        {
            try
            {
                string expresionPostfija = textBox1.Text;
                expresionPostfija = expresionPostfija.Trim();

                //MessageBox.Show(expresionPostfija);
                int resultado = Infija.Evaluar(expresionPostfija);
                textBox1.Text = resultado.ToString()+" ";
            }
            catch (Exception ex)
            {
                MessageBox.Show("Error en la expresión: " + ex.Message);
            }
        }

        private void button16_Click(object sender, EventArgs e)
        {
            textBox1.Clear();
        }
    }
}
