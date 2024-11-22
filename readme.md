Nomes:
Henrique Pacifico RM: 560289
Matheus Machado Caposse RM: 560340

Link do repositório no github : https://github.com/hpacifico777/GS-EDGE

Link do vídeo no youtube : https://youtu.be/5QhyeCvkMK8

Iluminação Pública Inteligente Alimentada por Energia Solar
Este projeto visa implementar um sistema de iluminação pública inteligente alimentado por energia solar, utilizando sensores de luminosidade e movimento. 
A principal função do sistema é controlar automaticamente os LEDs ou lâmpadas com base na luminosidade do ambiente e na presença de movimento, garantindo eficiência energética e sustentabilidade. 
O sistema é projetado para ser alimentado por energia solar, reduzindo a necessidade de eletricidade da rede e contribuindo para a preservação ambiental.

Objetivos do Projeto:
Automatização da Iluminação: Ativar e ajustar a intensidade da luz automaticamente com base na luminosidade do ambiente e detecção de movimento.
Eficiência Energética: Garantir o uso de energia solar para alimentar o sistema, sem depender da rede elétrica.
Economia de Energia: Acender os LEDs apenas quando necessário, ajustando o brilho conforme a presença de movimento e a quantidade de luz natural.
Sustentabilidade: Usar painéis solares como fonte de energia renovável para alimentar o sistema de iluminação.

Funcionamento:
Leitura da Luminosidade:
O sensor LDR (Light Dependent Resistor) monitora a luminosidade do ambiente. 
Quando a luminosidade é baixa (por exemplo, à noite ou em áreas com sombra), o sistema ativa o controle da iluminação.

Detecção de Movimento:
O sensor PIR (Passive Infrared Sensor) detecta a presença de movimento na área. 
Se houver movimento, o sistema acende o LED com brilho máximo.
Se não houver movimento, o LED acende com um brilho reduzido para economizar energia.

Controle de LEDs:
O LED ou lâmpada é acionado com base nos sinais dos sensores de luminosidade e movimento. 
Se a luminosidade ambiente estiver baixa e houver movimento, o LED acende com brilho máximo. 
Se não houver movimento, o LED acende com brilho reduzido. Durante o dia ou em ambientes bem iluminados, o sistema desliga os LEDs.

Alimentação Solar:
O sistema é alimentado por energia solar. O painel solar converte a luz do sol em eletricidade, que é armazenada em uma bateria recarregável. 
A energia da bateria é usada para alimentar o circuito e os LEDs durante a noite.