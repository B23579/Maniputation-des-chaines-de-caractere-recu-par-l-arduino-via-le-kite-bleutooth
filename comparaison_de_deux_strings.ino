#include <SoftwareSerial.h>
#include <String.h>
 // paramettre de configuration du bleutooth    
              #define RX 4
              #define TX  2
               SoftwareSerial BT(RX,TX);
void bleutooth();  
void setup() {
  Serial.begin(9600);
           // paramettre bleutooth
                  BT.begin(9600);
                  pinMode(RX,INPUT);
                  pinMode(TX,OUTPUT);
  // put your setup code here, to run once:

}

void loop() {
  bleutooth();

}
 String ph;  // déclaration des variables globales
 char mot[2];
            int i=0, dispo;
            long a=0;
void bleutooth(){
  dispo=BT.available();
            if(dispo>0){
                mot[1]=BT.read();
                
                if(mot[1]!='\n'){// si cette condition n'est pas teste alors à la fin de recupération des caractères dans le buffer il y aura \n a la fin qui va dérange au niveau 
                // des testes
                 ph =ph+  mot[1];// pour effectuer une concarténation
              }
               if(mot[1]=='\n'){ 
                    Serial.println(ph); 
                  if(ph=="avance"){
                    Serial.println("yes"); 
                    }
                    if(ph=="gauche"){
                    Serial.println("je respecte"); 
                    }
                    if(ph=="droite"){
                    Serial.println("ha! ha ha!"); 
                    }
                    if(ph=="retour"){
                    Serial.println("pas possible"); 
                    }
                    if(ph=="stop"){
                    Serial.println(" bouge"); 
                    }
                    
            
                  mot[1]='v';
                  ph="";// on vide le string
            }
            }
            }
