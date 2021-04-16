# Data_Structures-card_games-

Nota: Toate functiile din "utils.h" au un comentariu
despre ce ar trebui sa faca fiecare.

-----------------------------------------------------

main:

In functia main sunt declarate fisierele, vectorii 
auxiliari, lista (pachetul de carti), dar si unde vor
fi apelate majoritatea functiilor pentru rezolvarea
problemelor. 

------------------------------------------------------

Crearea pachetului de carti:

Cu ajutorul vectorilor auxiliari (v - valoarea cartii
, c - numele cartii, t - culoarea cartii) si functiei
"populate_list" am creat pachetul sub forma de lista
simplu inlantuita. De asemenea cu ajutorul functiei,
"print_list" putem sa afisam direct in fisierul "out"
pachetul de carti, lucru ce o sa ne ajute la amestecare.

------------------------------------------------------ 

Amestecare - Inversare

Cu ajutorul functiei invert_list inversam pachetul de 
carti. Functia schimba predecesorul nodului cu succeso-
rul acestuia.

Amestecare - N-piles 

Prin intermediul functiei n_piles si cu ajutorul unui
vector de liste stocam N pachete de carti. De asemenea,
am creat un reminder pentru a recunoaste cate carti
raman in plus pentru a le repartiza printre primele
pachete, cum ar fi normal intr-un joc de carti.
Cu ajutorul functiei getNth ( functie din "utils.h") 
recunosc mai repede head-ul fiecarui pachet.

Amestecare - Intercalare

Cu ajutorul functiei intercalation intercalam pachetul.
Impartim pachetul in doua, iar apoi legam primul nod
din primul pachet la primul nod din al doilea pachet,
primul nod din al doilea pachet il legam la al doilea nod
din primul pachet si asa mai departe.

Amestecare - Mongean

Cu ajutorul functiilor Mongean, insert_first si insert_last
(explicate pe scurt in "utils.h") realizam acest tip de 
sortare. Luam fiecare nod in parte si il inseram ( in
functie de paritatea si imparitatea unui iterator) la
sfarsit sau la inceputul noului pachet.

-------------------------------------------------------

Razboi

Cu ajutorul functiei War vom realiza jocul razboi.
Vom folosi o stiva pentru "masa" jocului unde vom
stoca cartile puse jos. Printr-un for o sa jucam cele
o suta de maini, daca este necesar. In acest for verificam
la fiecare mana daca un jucator a ramas fara carti, daca da,
rezulta ca celalalt jucator a castigat. Daca jocul continua,
verificam cine castiga mana. Daca nu e razboi, persoana cu
cartea cu valoarea mai mare castiga si primeste ambele carti,
insa daca e egalitate verificam mai intai cate carti o sa fie
puse in joc ( minimul dintre numarul de carti ale jucatorilor si
valoarea cartii jucate). Dupa ce ambii jucatori si au pus cartile
pe masa verificam din nou cine castiga mana. Daca jocul nu s-a
terminat in cele o suta de maini, verificam cine are cele mai
multe carti cu cea mai mare valoare ( ex: cine are mai multi asi
castiga. Daca este egalitate, se trece la urmatoarea carte).
Acest lucru se realizeaza cu vectorul c( cards)

-------------------------------------------------------

Rolling Stone

Prin intermediul functiei Rolling_Stone vom realiza jocul
rolling stone. Impartim printr-un vector de liste pachetele
celor 4 jucatori. Cream de asemenea si o stiva care va fi
"masa" de joc, unde vom stoca cartile jucate. Tinem cont 
de ce jucator va incepe prin "aux". La inceputul fiecarei
runde verificam ce culoare se va juca prin intermediul functiei
check_type_card. In continuare verificam daca jucatorul a ramas
fara carti, daca da, acesta a castigat, daca nu, jocul contiuna.
Dupa ce a trecut randul primului jucator se trece la urmatorul care
este obligat sa joace culoarea ce este deja pe masa, daca acesta
nu are acel tip de carte, acesta este obligat sa ia toate cartile
de pe masa, urmand ca el sa inceapa jocul.  Ciclul se repeta
pana un jucator ramane fara carti.



--------------------------------------------------------

Scarabeii Egipteni

Prin intermediul functiei Scarabei vom realiza jocul scarabeii
egipteni. Impartim pachetul printr-un vector de liste, cream
stiva sau "masa" jocului. O sa avem nevoie de: un vector
pentru a retine ce jucatori mai sunt in joc, numarul de jucatori
care au iesit, sa retinem ce jucator urmeaza, ce jucator a 
castigat mana si sa retinem in ce directie este jocul. La fiecare
runda verificam daca jucatorul ce urmeaza are carti si daca nu
cumva a castigat. Daca nu a gastigat, jocul continua. Daca masa
e goala, primul jucator va pune fara probleme prima carte pe masa.
Daca valoarea cartii este mai mare de 12, atunci cartea este
Scarabeu si il obliga pe urmatorul jucator sa puna si el
un Scarabeu.Daca urmatorul jucator nu pune un Scarabeu sau un 8, jucatorul
precedent castiga mana, Daca acesta pune un Scarabeu, jocul contiuna,
obligand urmatorul jucator sa puna un Scarabeu. Daca acesta pune
un 8 se schimba sensul si se continua. Revenim la jucatorul inital.
Daca acesta pune o carte mai mica decat 12 si diferita de 8,
jocul contiuna fara probleme. Daca acesta pune un 8, se schimba
sensul. Daca un jucator ramane fara carti, acesta este scos din joc,
ca intr-un final sa ramana un singur jucator.

---------------------------------------------------------
