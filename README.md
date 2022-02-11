# Identificação Pessoal

- Nome: *Rafael Silva Freire*
- Email: *rafaelsilvafreire2@gmail.com*
- Turma: *DIM0117 - T01*

- Nome: *Thiago de Oliveira Cordeiro*
- Email: *thiagoty52@gmail.com*
- Turma: *DIM0117 - T01*

# Softwares necessários
 * Git
 * Compilador de C++ (indicado G++)
 * Cmake (opcional)

# Compilando e executando

## Manualmente com g++

Para compilar e executar o programa manualmente basta digitar os seguintes comandos em seu terminal:

```
$ git clone git@github.com:davi-i/cpp-arvore-de-busca.git (faz o clone do repositório em algum diretório do seu pc)
$ cd cpp-arvore-de-busca/ (vai até a pasta do repositório clonado)
$ mkdir build (caso não tenha uma pasta para os executáveis, você deve criá-la com esse comando)
$ g++ -Wall -std=c++17 -g -I include source/main.cpp source/tree.cpp source/utils.cpp -o build/tree (compilar)
$ ./build/tree <arquivo da arvore> <arquivo de comandos> (executar)
```

## Cmake

Para compilar e executar o programa com o Cmake você precisa ter instalado pelo menos a versão 3.8. Em seguida, abra seu terminal e execute os seguintes comandos:
```
$ git clone git@github.com:davi-i/cpp-arvore-de-busca.git (faz o clone do repositório em algum diretório do seu pc)
$ cd cpp-arvore-de-busca/ (vai até a pasta do repositório clonado)
$ mkdir build (caso não tenha uma pasta para os executáveis, você deve criá-la com esse comando)
$ cmake -S source -B build (criar o cmake do projeto)
$ cmake --build build (compilar)
$ ./build/tree <arquivo da arvore> <arquivo de comandos> (executar)
```

--------
&copy; IMD/UFRN 2022.
