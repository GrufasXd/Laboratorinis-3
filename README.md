Atsisiuntus pateikta aplankalą reikia jį atidaryti programavimo aplinkoje, pvz (VS code).
Programavimo aplinkos terminale parašyti "make -f MakefileVector", "make -f MakefileList" arba "make -f MakefileDeque" norint sukompiliuoti atitinkamai, vector, list ir deque failus.
Tada parašyti "./main_vector", "./main_list" arba "./main_deque" tam pačiam terminale norint paleisti programą veikiančią su atitinkamais konteineriais.
Jeigu viskas buvo įrašyta teisingai, programa pasileis ir prašys pasirinkti rūšiavimo strategiją - 1, 2 ar 3 kurią lengvai galite pasirinkti paspaudę atitinkamą skaičių. Pasirinkus strategiją galėsite pasirinkti studentų rūšiavimo kriterijų(pagal galutinį pažymių vidurkį, arba pagal medianą) prieš tai parodydama kiek laiko užtruko sukurti failą (kadangi failai įeina į atsisiųstą aplankalą laikas bus 0 sec).
Programa nuskaitys sukurtą failą, surušiuos jį pagal pasirinktą kriterijų ir viską išves į 2 naujus failus vargsai.txt ir galva.txt(galva.txt - rodo kriterijų atitinkančius studentus kurių mediana arba vidurkis yra didesnis arba lygus 5, o vargsai.txt rodys studentus kurių mediana arba vidurkis yra mažesnis už 5) ir lauks kol jūs paspausite "Enter" mygtuką. Kol laukiate galite atsidaryti failus vargsai.txt ir galva.txt ir patikrinti arba apžvelgti rūšiavimą.
Kai programa baigs rūšiuoti paskutinį failą bus rodomas kiek laiko užtruko visas kodas.

Makefile atsisiuntimas - 

1 žingsnis - Įdiekite MinGW paketų tvarkyklę. tai galite padaryti šios nuorodos pagalba https://sourceforge.net/projects/mingw/  ir paspaudę mygtuką "Install"

2 -žingsnis - Nustatykite vietą, kur norite įdiegti MinGW paketų tvarkyklę. Kai naršyklės viršuje rodys, kad siuntimas baigtas, 2 kart paspauskit ant atsisiųsto failo.

3 -žingsnis - Atsidariusiam programos lange spauskite "Install".

4 - žingsnis - Paspausti pasirinkimo laukelį prie kurio parašyta "... also install support for graphical user interface"

5 - žingsnis - Laukti kol atisiųs MinGW.

6 - žingsnis - Eikite į „C“ diską, atidarykite „MinGW“ aplanką ir suraskite „mingw-get.exe“ failą. Nukopijuokite failo vietą.

7 - žingsnis - Apačioje, pradiniame meniu, ieškokite „Environment Variables“ ir atidarykite juos.

8 - žingsnis - Paspauskite „Environment Variables“ mygtuką, kad nustatytumėte kelią aplinkos kintamuosiuose.

9 - žingsnis - Iš „System Variables“ (sistemos kintamųjų) panelės pasirinkite „Path“ ir paspauskite „Edit“ mygtuką.

10 - žingsis - Po to, paspauskite „New“ mygtuką ir įklijuokite nukopijuotą kelią į Path lauką. Tada spauskite „Ok“ mygtuką.

11 - žingsnis: Pradiniame meniu ieškokite „CMD“ ir atidarykite komandų eilutę.

12 - žingsnis - Tada, vykdykite pateiktą komandą, kad įdiegtumėte make į Windows: "mingw-get install mingw32-make".

13 - žingsnis - Patikrinkite make komandos įdiegimą tikrindami jos versiją: "mingw32-make --version" Jeigu po šios komandos matote instaliuotą versiją, vadinasi viską padarėte gerai.

Programas laikas, su sukurtais failais -

<img width="576" alt="irdouasnmd 1" src="https://github.com/GrufasXd/Laboratorinis-1/assets/147091694/edb2dbe7-1bbd-449b-b648-966e7daa2ec6">

<img width="576" alt="irodumas 2" src="https://github.com/GrufasXd/Laboratorinis-1/assets/147091694/17c4c376-2d7f-46cd-9083-8928e3d334af">

Failų kūrimas - 

<img width="576" alt="irdoyumas 3" src="https://github.com/GrufasXd/Laboratorinis-1/assets/147091694/4ee71c75-34d6-4bf6-a0fe-af1afdc12143">

<img width="576" alt="irdoymas 4" src="https://github.com/GrufasXd/Laboratorinis-1/assets/147091694/d236d610-268d-485c-a9f0-06691dc3f859">

Vector 1 strategijos laikai - 

<img width="786" alt="vector 1 1" src="https://github.com/GrufasXd/Laboratorinis-1/assets/147091694/83d2abe8-d3be-42fc-8d07-33b6ee4599bf">

<img width="576" alt="vector 1 2" src="https://github.com/GrufasXd/Laboratorinis-1/assets/147091694/5354322c-06e6-4c78-9908-6787023072c2">

<img width="632" alt="vector 1 3" src="https://github.com/GrufasXd/Laboratorinis-1/assets/147091694/ffbd03b4-8ecd-4c3d-8222-d22d0c9999ec">

<img width="576" alt="vector 1 4" src="https://github.com/GrufasXd/Laboratorinis-1/assets/147091694/9104f41e-d8b0-46fb-a77c-900f3088ff32">

Vector 2 strategijos laikai -

<img width="788" alt="vector 2 1" src="https://github.com/GrufasXd/Laboratorinis-1/assets/147091694/ae99dbb2-fc74-44e1-afd9-2c6045ce0be7">

<img width="674" alt="vector 2 2" src="https://github.com/GrufasXd/Laboratorinis-1/assets/147091694/d8e8ed3f-c109-4875-96aa-17d045de9954">

<img width="774" alt="vector 2 3" src="https://github.com/GrufasXd/Laboratorinis-1/assets/147091694/4465c24a-2675-47b6-bcfc-ae88d9805cb5">

<img width="779" alt="vector 2 4" src="https://github.com/GrufasXd/Laboratorinis-1/assets/147091694/2c680986-1367-41f3-a344-758db8c0a16a">

Vector 3 strategijos laikai -

<img width="818" alt="vector 3 1" src="https://github.com/GrufasXd/Laboratorinis-1/assets/147091694/a3720b9b-f0ab-49e2-ae88-c1b3b68329d3">

<img width="820" alt="vector 3 2" src="https://github.com/GrufasXd/Laboratorinis-1/assets/147091694/e767beb9-6dac-489c-9856-2d87f26ba9dd">

List 1 strategijos laikai -

<img width="786" alt="list 1 1" src="https://github.com/GrufasXd/Laboratorinis-1/assets/147091694/6d5e7ad1-c263-44da-b3d6-215183cb654c">

<img width="576" alt="list 1 2" src="https://github.com/GrufasXd/Laboratorinis-1/assets/147091694/3b15981e-7475-41e0-91bf-f695e6eedd4b">

<img width="784" alt="list 1 3" src="https://github.com/GrufasXd/Laboratorinis-1/assets/147091694/bae3df54-0296-440f-a80b-6d5de1e570d5">

<img width="576" alt="list 1 4" src="https://github.com/GrufasXd/Laboratorinis-1/assets/147091694/17ab3254-cc37-42ae-af4f-1f0f0013b988">

List 2 strategijos laikai - 

<img width="786" alt="list 2 1" src="https://github.com/GrufasXd/Laboratorinis-1/assets/147091694/a5f827aa-57d3-4da2-963b-d20152c97da9">

<img width="784" alt="list 2 2" src="https://github.com/GrufasXd/Laboratorinis-1/assets/147091694/8a1ff412-f2fa-4c6b-8e39-3461ccf40412">

<img width="789" alt="list 2 3" src="https://github.com/GrufasXd/Laboratorinis-1/assets/147091694/fe2a2fa6-d19c-443f-8256-274ee13fcf8d">

<img width="771" alt="list 2 4" src="https://github.com/GrufasXd/Laboratorinis-1/assets/147091694/b3e66905-f0ff-487e-b4a8-4c17d3a89af7">

List 3 strategijos laikai -

<img width="817" alt="list 3 1" src="https://github.com/GrufasXd/Laboratorinis-1/assets/147091694/09e3c301-100d-4e70-b1ef-e46aa7b35158">

<img width="819" alt="list 3 2" src="https://github.com/GrufasXd/Laboratorinis-1/assets/147091694/53b8dc96-8ad7-4e49-879f-b858aa190d1d">

Deque 1 strategijos laikai - 

<img width="787" alt="deque 1 1" src="https://github.com/GrufasXd/Laboratorinis-1/assets/147091694/adee377f-4fce-441c-b92e-8abf74762d28">

<img width="784" alt="deque 1 2" src="https://github.com/GrufasXd/Laboratorinis-1/assets/147091694/99aa7557-4be8-4ac6-934b-176d0ab7b3f6">

<img width="788" alt="deque 1 3" src="https://github.com/GrufasXd/Laboratorinis-1/assets/147091694/86c373bd-9561-4f89-825e-d25cf25bbcce">

<img width="788" alt="deque 1 4" src="https://github.com/GrufasXd/Laboratorinis-1/assets/147091694/f4654bd2-0b90-45eb-9bf1-af09c6d87050">

Deque 2 strategijos laikai - 

<img width="788" alt="deque 2 1" src="https://github.com/GrufasXd/Laboratorinis-1/assets/147091694/b4da068f-ccf2-48ed-ac5b-0bb39e5c65dd">

<img width="785" alt="deque 2 2" src="https://github.com/GrufasXd/Laboratorinis-1/assets/147091694/a08be643-aece-465b-9751-f279591dd3b3">

<img width="793" alt="deque 2 3" src="https://github.com/GrufasXd/Laboratorinis-1/assets/147091694/57a0c65f-c283-4de0-a171-d028c05aaca4">

<img width="788" alt="deque 2 4" src="https://github.com/GrufasXd/Laboratorinis-1/assets/147091694/9fa5f018-2ee9-4d3e-a331-5414d1970849">

Deque 3 strategijos laikai - 

<img width="790" alt="deque 3 1" src="https://github.com/GrufasXd/Laboratorinis-1/assets/147091694/f47af7f0-2e38-4971-af34-508cde8593b0">

<img width="783" alt="deque 3 2" src="https://github.com/GrufasXd/Laboratorinis-1/assets/147091694/e33c4068-870c-4955-a7e0-43a85cf3ae5c">

<img width="817" alt="deque 3 3" src="https://github.com/GrufasXd/Laboratorinis-1/assets/147091694/84279e75-daaf-46cd-b054-7206d046e578">

Pirmam pre-release buvo atliekami testai su visais konteineriais tik 1 strategija. 
Šiame pilname release buvo testuojamos papildomai 2 ir 3 strategijos. 2 Visiem konteinerių tipam - tokia pati. 3 strategija - patobulinta versija greitesnės strategijos iš pirmų dviejų pagal konteinerį.
Su list konteineriu buvo patobulinta 2 strategija, o su vector ir deque konteineriais patobulinta 1 strategija.

Sistemos parametrai - 
SSD - SAMSUNG MZNLN256HAJQ-00007
CPU - Intel(R) Core(TM) i7-8565U CPU @ 1.80GHz
Instaliuoti Ramai - 16GB

