Membros/matrícula: Beatriz Hanae Fujimoto 16/0113814  
<td>&emsp;</td><td>&emsp;</td><td>&emsp;</td><td>&emsp;</td><td>&emsp;</td><td>&emsp;</td><td>&emsp;</td><td>&emsp;</td>Marcelo Araújo dos Santos 16/0035481           

# DIA DE DOAR

Link do vídeo com demonstração do projeto: (obs: executar comando "sudo apt-get install imagemagick" antes)
* https://www.youtube.com/watch?v=sv3XB-S0XOo&t=1s


## Introdução:
<td>&emsp;</td>O site Dia De Doar é uma aplicação elaborado na linguagem Ruby on rails, que foi proposto como projeto de avaliação para os alunos da disciplina de Orientação à Objetos.O site permite a troca de produtos. Quando uma pessoa não quer mais algum objeto ja usado, ou até mesmo sabe que não usará, e ao invés de jogar fora ou vender, ele "doa".

## Execução do Programa:
<td>&emsp;</td>Antes de executar a aplicação, precisamos verificar as versões do seu computador:

* Versão do Ruby:   2.4.2
* Versão do Rails:  5.1.4

Para executar:

* Para instalar programa de tratar imagem:

 `sudo apt-get install imagemagick`

* No terminal:

  `git clone https://gitlab.com/marcelo_604/ep3.git `  
  `cd ep3`  
  `rake db:migrate`  
  `bundle install`  
  `rails s`  


## Características principais do site:

<td>&emsp;</td> Ao entrar no site, na página principal encontra se disponível um menu no topo com "Página Principal", "Produtos", "Como funciona", "Cadastrar" e "Entrar".

<td>&emsp;</td> Quando logado no site o usuário cadastrado possui a opção de no local "Minha Conta", editar, deslogar e  entrar nos produtos dele, sendo que nesse campo ele pode adicionar, excluir, editar os produtos que gostaria de doar.

<td>&emsp;</td> Quando o um usuário tiver interesse em algum produto disponível no site, ele poderá clicar em "EUQUERO" e isso encaminha um e-mail, com dados do e-mail e telefone do interessado, para o doador responsável pelo produto. Assim entre eles o contato é direto e acordos como onde buscar, ou outras informações podem ser acordadas.  


