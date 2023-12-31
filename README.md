**# AAcompositionPercent**

**Get the aminoacid composition of a given protein sequence in FASTA format

Gives the percentage of aminoacids in a sequence (Standard code). FASTA file can be a single protein or many. If file contains many proteins, script will give the overall aminoacid percentages in all of the entries.
Example FASTA file
**

>sp|A0A0B4J2F0|PIOS1_HUMAN Protein PIGBOS1 OS=Homo sapiens OX=9606 GN=PIGBOS1 PE=1 SV=1
MFRRLTFAQLLFATVLGIAGGVYIFQPVFEQYAKDQKELKEKMQLVQESEEKKS
>sp|A0A0B4J2F2|SIK1B_HUMAN Putative serine/threonine-protein kinase SIK1B OS=Homo sapiens OX=9606 GN=SIK1B PE=5 SV=1
MVIMSEFSADPAGQGQGQQKPLRVGFYDIERTLGKGNFAVVKLARHRVTKTQVAIKIIDK
TRLDSSNLEKIYREVQLMKLLNHPHIIKLYQVMETKDMLYIVTEFAKNGEMFDYLTSNGH
LSENEARKKFWQILSAVEYCHDHHIVHRDLKTENLLLDGNMDIKLADFGFGNFYKSGEPL
STWCGSPPYAAPEVFEGKEYEGP


**Usage:** python overallaacomp.py FILE


_**If you wish to get the composition of many individual files, you can simply iterate over the files.**_

for f in *.fasta; do overallaacomp.py "$f"; done

