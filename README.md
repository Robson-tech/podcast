# PODCAST

Interface de controle desenvolvida em C para utilização via terminal que gerencia modelos de dados relacionados a plataformas de áudio.

## LISTA DE COMANDOS BÁSICOS:
* Buscar
* Imprimir
* Inserir
* Remover
* Ajuda
* Sair

## IDEIA DE USO

```
buscar ("plataforma")
buscar ("plataforma", "podcast")
buscar ("plataforma", "podcast", "tema")
buscar ("plataforma", "podcast", "tema", "entrevista")
```
```
imprimir
imprimir ("plataforma")
imprimir ("plataforma", "podcast")
imprimir ("plataforma", "podcast", "tema")
```
```
inserir (plataforma, "nome")
inserir (podcast, "nome", "entrevistador", "plataforma")
inserir (tema, "tipo", "podcast")
inserir (entrevista, "titulo", "data", duracao, "entrevistado", "especialidade", "tema")
```
```
remover ("plataforma")
remover ("plataforma", "podcast")
remover ("plataforma", "podcast", "tema")
remover ("plataforma", "podcast", "tema", "entrevista")
```
```
ajuda buscar
ajuda imprimir
ajuda inserir
ajuda remover
```

```sair```