library(readxl)

library(dplyr)


tempoInicial<-Sys.time()
  
#lendo do arquivo xlsx
tabela_ini <- read_excel("../FECHAMENTO_MAIS__NEGOCIADAS_5minutos.xlsx")

#printando matriz total
print(tabela_ini)

#removendo a primeira coluna
tabela_wd <- (select(tabela_ini,-DATA))

#printando sem a primeira coluna
print(tabela_wd)

#criando a matriz 12x12 que será modificada no loop
tabela_loop<-(tabela_wd[1:12, nrow=12, ncol=12])

#printando a primeira matriz
print(tabela_loop)

#gerando a inversa da primeira matriz
inversa <- solve(tabela_loop)

#printando a inversa da primeira matriz
print(inversa)

i<-12

for(i in 12:6200)
{
  
  #tira a primeira linha
  tabela_loop <- (slice(tabela_loop,-1))
  
  #copia a proxima linha pra variavel linha
  linha <- tabela_wd[i+1,]
  
  
  #coloca na tabela a proxima linha
   tabela_loop <- add_row(tabela_loop,linha)

  #gerando a inversa da matriz
  inversa <- solve(tabela_loop)

  
  print(inversa)
}

tempoFinal<-Sys.time()

print(tempoFinal-tempoInicial)

