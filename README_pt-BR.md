# Exemplo de conexão entre esp8266 e python via TCPsocket

Esse código é basicamente um exemplo de como conectar um [esp8266](https://pt.wikipedia.org/wiki/ESP8266) (ou outro da família, com wifi) a um computador ou outro dispositivo (como um Raspberry Pi) rodando Python. A conexão é feita via wifi, usando a pilha TCP/IP como suporte.

## Problemática

Sempre houve a necessidade de conectar dispositivos wifi como o esp8266 com facilidade a outros, principalmente pela questão IoT. Desse modo, o python se sai muito bem, tanto pela facilidade de programação quanto pela riqueza de bibliotecas.

Existem, basicamente, duas formas de conectar o esp8266 a outros dispositivos via wifi: por HTTP requests e por TCPsockets. O primeiro é muito mais abordado na internet, principalmente entre dois esp8266.

A conexão via HTTP requests possui a vantagem de permitir vários clientes para um mesmo servidor, mas nem sempre é o que se deseja.

Por outro lado, a conexão via TCPsocket trata da conexão direta entre dois dispositivos apenas (como um túnel), de modo que apenas strings são enviadas de um para outro, diretamente. 

## Objetivo

O objetivo desse código é ceder um exemplo de como conectar um microcontrolador esp8266 a um pc via python de uma forma bastante simples, usando apenas a biblioteca ```socket``` do python, que é built-in. Da mesma forma que eu precisei e encontrei essa solução, assim também estou ajudando 😎. Apenas observe os códigos e adapte à sua situação.


## Avisos

É importante verificar se a porta escolhida está aberta à conexões no firewall. No Windows, isso se verifica nas configurações do sistema (ou do antivírus, se houver).

Em Linux, pode-se abrir a porta usando o seguinte [comando](https://www.cyberciti.biz/faq/linux-unix-open-ports/) (foi usada a porta já escrita no programa como exemplo):

```(bash)
sudo iptables -A INPUT -m state --state NEW -m tcp -p tcp --dport 8080 -j ACCEPT
sudo service iptables save
```

## Planos futuros

Está em análise a possibilidade de programar uma API futuramente, de modo que seja necessário apenas o instanciamento de um objeto ```WiFiSocket``` em ambos os lados, de modo que, por exemplo

```(python)
soc = WiFiSocket()
soc.send('Hi')
answer = soc.receive()
```

seja o bastante para garantir a conexão entre os dois nós.


## Créditos
Admito, esse código não é meu. Foi uma solução retirada de alguma página na internet há alguns anos, então eu não lembro o autor. Porém, o código foi otimizado para conter apenas o essencial.

## License
[MIT](https://choosealicense.com/licenses/mit/)
