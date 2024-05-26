Atsisiuntus pateikta aplankalą reikia jį atidaryti programavimo aplinkoje, pvz (VS code).
Programavimo aplinkos terminale parašyti žodį "make".
Tada parašyti "./main" tam pačiam terminale.
Jeigu viskas buvo įrašyta teisingai, programa pasileis ir prašys pasirinkti studentų rūšiavimo kriterijų(pagal galutinį pažymių vidurkį, arba pagal medianą) prieš tai parodydama kiek laiko užtruko sukurti failą (kadangi failai įeina į atsisiųstą aplankalą laikas bus 0 sec).
Programa nuskaitys sukurtą failą, surušiuos jį pagal pasirinktą kriterijų ir viską išves į 2 naujus failus vargsai.txt ir galva.txt(galva.txt - rodo kriterijų atitinkančius studentus kurių mediana arba vidurkis yra didesnis arba lygus 5, o vargsai.txt rodys studentus kurių mediana arba vidurkis yra mažesnis už 5) ir lauks kol jūs paspausite "Enter" mygtuką. Kol laukiate galite atsidaryti failus vargsai.txt ir galva.txt ir patikrinti arba apžvelgti rūšiavimą.
Kai programa baigs rūšiuoti paskutinį failą jūsų bus prašoma pasirinkti, ar norite duomenis generuoti/rasyti ranka, ar duomenis skaityti iš failo.

Pasirinkus duomenis generuoti/rasyti ranka bus matomas naujas pasirinkimų meniu su pasirinkimais kaip tiksliai apdoroti duomenis(viska rasyti ranka - 1, generuoti tik pazymius - 2, generuoti pazymius, studentu vardus bei pavardes - 3, baigti darba - 4).
Pasirinkus viską rašyti ranka reikės suvesti: studento vardą, pavardę, pažymių kiekį, pažymius ir egzamino rezultatą. Pasirinkus generuoti pažymius reikės suvesti: studento vardą, pavardę, pažymių kiekį ir egzamino rezultatą. Viską generuojant reikės suvesti tik pažymių kiekį ir egzamino rezultatą.
Įrašius egzamino rezultatą bus rodoma ta pati lentelė(jeigu norite pridėti dar vieną studentą - galite toliau pasirinkti arba generuoti arba rasyti duomenis ranka, jei ne spauskite 4).
Programos pabaigoje, bus rodomi visi įvesti/sugeneruoti mokiniai su savo bendrais vidurkiais ir medianom.

Pasirinkus skaityti duomenis iš failo, bus rodomas meniu iš 3 pasirinkimų - 10tūkst., 100tūkst. ir 1mil. duomenų failų.
Pasirinkus failą bus rodomas meniu kuriame prašoma pasirinkti rūšiavimo tipą(
Pagal varda - 1
Pagal pavarde - 2
Galutini pazymiu vidurki - 3
Galutini pagal mediana - 4)
Parašius bet kurį iš nurodytų skaičių, duomenys bus surūšiuoti pagal tą kriterijų.
Po rūšiavimo atsiras dar vienas meniu kuriame jūsų bus klausiama kur duomenis spausdinti(
Ar duomenis spausdinti ekrane - 1
Ar duomenis spausdint faile - 2)
Pasirinkus 1 - duomenys spausdinami ekrane, pasirinkus 2 - duomenys spausdinami faile(outputas.txt).
Programos pabaigoje rodomas visas programos laikas.

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

List 1 strategijos laikai -

<img width="786" alt="list 1 1" src="https://github.com/GrufasXd/Laboratorinis-1/assets/147091694/6d5e7ad1-c263-44da-b3d6-215183cb654c">

<img width="576" alt="list 1 2" src="https://github.com/GrufasXd/Laboratorinis-1/assets/147091694/3b15981e-7475-41e0-91bf-f695e6eedd4b">

<img width="784" alt="list 1 3" src="https://github.com/GrufasXd/Laboratorinis-1/assets/147091694/bae3df54-0296-440f-a80b-6d5de1e570d5">

<img width="576" alt="list 1 4" src="https://github.com/GrufasXd/Laboratorinis-1/assets/147091694/17ab3254-cc37-42ae-af4f-1f0f0013b988">

Deque 1 strategijos laikai - 

<img width="787" alt="deque 1 1" src="https://github.com/GrufasXd/Laboratorinis-1/assets/147091694/adee377f-4fce-441c-b92e-8abf74762d28">

<img width="784" alt="deque 1 2" src="https://github.com/GrufasXd/Laboratorinis-1/assets/147091694/99aa7557-4be8-4ac6-934b-176d0ab7b3f6">

<img width="788" alt="deque 1 3" src="https://github.com/GrufasXd/Laboratorinis-1/assets/147091694/86c373bd-9561-4f89-825e-d25cf25bbcce">

<img width="788" alt="deque 1 4" src="https://github.com/GrufasXd/Laboratorinis-1/assets/147091694/f4654bd2-0b90-45eb-9bf1-af09c6d87050">

Sistemos parametrai - 
SSD - SAMSUNG MZNLN256HAJQ-00007
CPU - Intel(R) Core(TM) i7-8565U CPU @ 1.80GHz
Instaliuoti Ramai - 16GB

