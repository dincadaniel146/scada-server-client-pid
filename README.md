# Sistem SCADA realizat in LabWindows/CVI

## Arhitectura sistemului

Partea de server incapsuleaza Partea Fixa formata din proces, traductoare si elemente de executie. Aceasta poate functiona si in modul "Manual", adica fara o aplicatie Client conectata. 
 
Partea de client incapsuleaza solutia de control (PID) care poate fi realizata in momentul in care avem o conexiune cu serverul. 

# Interactiunea server-client

Serverul se initializeaza si se inregistreaza pe un port specificat, asteptand conectarea unui client. 

Clientul se conecteaza la server pe baza portului si a adresei IP. Acesta trimite comenzi de control si date catre server. Acestea pot fi comenzi pt. a actualiza parametrii procesului sau pentru a solicita informatii de stare. 

Serverul proceseaza aceste comenzi, efectueaza calculele necesare si trimite date actualizate catre client. In acelasi timp, serverul isi actualizeaza graficul si indicatorii pentru a reflecta starea curenta a procesului.

