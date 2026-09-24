# Data Struct Visualizer

[![Licença](https://img.shields.io/badge/License-MIT-blue.svg)](https://opensource.org/licenses/MIT) [![Status do Projeto](https://img.shields.io/badge/Status-Ativo-brightgreen.svg)]()

> Solução encontrada para APS proposta durante a aula de Estrutura de Dados, lecionada pelo professor Manuel Martins.
---

## 📖 Índice

- [Sobre o Projeto](#-sobre-o-projeto)
- [Funcionalidades](#-funcionalidades)
- [Tecnologias Utilizadas](#-tecnologias-utilizadas)
- [Pré-requisitos](#-pré-requisitos)
- [Instalação e Execução](#-instalação-e-execução)
- [Como Usar](#-como-usar)
- [Licença](#-licença)
- [Contato](#-contato)

## 💡 Sobre o Projeto

Este projeto apresenta três estruturas de dados fundamentais (Lista, Fila e Pilha) com um objetivo central: facilitar a compreensão desses conceitos por estudantes de tecnologia através de uma interface visual, onde é possível ver e interagir diretamente com o funcionamento de cada estrutura na prática. Adicionalmente, o desenvolvimento consolida conhecimentos aplicados na linguagem C e na biblioteca gráfica Raylib.

## ✨ Funcionalidades

- **Seleção de Estruturas:** Alternância livre entre os ambientes interativos de Lista, Fila (FIFO) e Pilha (LIFO).
- **Renderização Visual em Tempo Real:** Representação gráfica das operações de inserção e exclusão de dados na memória.
- **Validação Restrita de Estados:** Bloqueio automático de operações inválidas, prevenindo overflow e underflow.
- **Ordenação e Realocação Automáticas:** Busca linear para ordenação crescente imediata na Lista Sequencial, com deslocamento lógico (shift) após remoções.
- **Monitoramento de Estado:** Acompanhamento visual da capacidade atual, informando claramente se a estrutura está vazia, disponível ou cheia.

## 🛠 Tecnologias Utilizadas

- **[Linguagem C](https://en.wikipedia.org/wiki/C_(programming_language))** - Base estrutural para o algoritmo, escolha feita baseada nas opções fornecidas pelo professor.
- **[Raylib](https://www.raylib.com/)** - Biblioteca gráfica utilizada para a renderização da interface 2D e gerenciamento do loop da janela. Conta com um [cheatsheet](https://www.raylib.com/cheatsheet/cheatsheet.html) longo e detalhado.
- **[GCC / MinGW-w64](https://www.mingw-w64.org/)** - Compilador nativo utilizado para transformar o código-fonte no executável autossuficiente para Windows.
- **[Make](https://www.gnu.org/software/make/)** - Automação da compilação via script 'Makefile'.

## ⚙️ Pré-requisitos

Antes de começar, certifique-se de ter as seguintes ferramentas instaladas em sua máquina:

- [Git](https://git-scm.com)
- [MinGW-w64 (GCC)](https://www.mingw-w64.org/)
- [Make](https://www.gnu.org/software/make/): MinGW-w64 já vem com ele nos arquivos. Bem provavelmente não será necessário um download individual.


## 🚀 Instalação e Execução

O executável independente pode ser baixado diretamente por aqui: [Download v1.0.0](https://github.com/yasrcha/data-struct-visualizer/releases/download/v1.0.0/v1.0.0.zip). Ou acesse a página do [release mais recente](https://github.com/yasrcha/data-struct-visualizer/releases/tag/v1.0.0) e baixe o arquivo disponível nos assets.

Se tem interesse em baixar o código e rodar ele na sua maquina, se certifique de ter todos os pré-requisitos instalados na sua maquina antes de seguir os passos abaixo:

**1. Clone o repositório:**

```bash
git clone https://github.com/yasrcha/data-struct-visualizer.git
```

**2. Acesse a pasta do projeto:**

```bash
cd data-struct-visualizer
```

**3. Compile o código-fonte:**

```bash
make
```

**4. Inicie a aplicação:**

```bash
./bin/DataStructVisualizer.exe
```

## 🎯 Como Usar

**1.** No menu principal, clique na estrutura de dados que deseja visualizar.

**2.** Na tela da estrutura, altere o valor numérico desejado utilizando a interface.

**3.** Clique em Insert para alocar o valor (a aplicação respeitará a regra de ordenação ou as políticas FIFO/LIFO automaticamente).

**4.** Clique em Remove para desalocar o elemento (indicando o valor específico na Lista, ou removendo das extremidades na Fila/Pilha).

**5.** Acompanhe os alertas visuais na tela indicando o preenchimento da estrutura.

**6.** Utilize o botão Back para retornar, limpando a estrutura atual.

## 📝 Licença
Distribuído sob a licença MIT. Veja o arquivo LICENSE para mais informações.

## 👩‍💻 Autora e Contato

**Yasmin Nascimento da Rocha** - *Graduanda em Ciência da Computação*

[![LinkedIn](https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/yasrcha/) [![GitHub](https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white)](https://github.com/yasrcha) [![E-mail](https://img.shields.io/badge/Email-D14836?style=for-the-badge&logo=gmail&logoColor=white)](mailto:yasminnasrocha@gmail.com)

> <span style="font-size: 15px; font-weight: bold;"> "Não deixem que ninguém calcule o valor da sua capacidade por vocês. Se quiserem alcançar as estrelas, não peçam permissão: apenas descubram a rota." - <span style="font-size: 12px; font-style: italic;"> Katherine Johnson </span></span>
