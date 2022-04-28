# WMR500_local

## Présentation
Le serveur __mqtt.idtlive.com__ ne fonctionnant a des moments aléatoire, j'ai décidé de trouver une solution d'hébergement local de leur station météo WMR500.

Voici les points qui seront décris:
- Un client TCP pour appairer la station météo à votre Wi-FI sans passer par l'application mobile.
- la mise en place de l'AP WI-FI pour la raspberry avec RaspAP
- la mise en place d'un broker mosquitto sur cette même raspberry
- DNS Spoofing pour ne pas utiliser le serveur amazonAWS qui est normalement utilisé sur l'adresse __mqtt.idtlive.com__


## Client TCP pour l'appairage

Le client TCP pour l'appairage de la WMR500 ([lien dl](https://github.com/GwendalT35/WMR500_local/releases/tag/1.0.0)) permet de connecter la console météo à un réseau WI-FI sans passer par l'application mobile **SmartLiving WMR500**.

Pour cela il vous faut seulement être connecter au réseau WIFI de votre console à appairer de nom **OS_WMR_XXXX** et entrez votre le SSID puis le mots de passe de votre AP.

## Raspberry et RaspAP

Comme solution basique on peut installer [RaspAP](https://www.google.com/url?sa=t&rct=j&q=&esrc=s&source=web&cd=&cad=rja&uact=8&ved=2ahUKEwiArrnntrb3AhVTSPEDHUebAZAQFnoECAYQAQ&url=https%3A%2F%2Fraspap.com%2F&usg=AOvVaw0FJ3fXlFUmgSZ2cxXtHEGK) sur une RaspberryPi sur laquelle on va appairer la console météo.

## Broker Mosquitto

Sur la raspberry on installe [Mosquitto](https://mosquitto.org/download/).

Vous pouvez retrouver le fichier de configuration que j'utilise [ici](https://github.com/GwendalT35/WMR500_local/blob/main/mosquittoConfWmr500.conf)

## DNS Spoofing

Sur la RaspberryPi on ajoute dans le fichier "[/etc/hosts](https://tldp.org/LDP/solrhe/Securing-Optimizing-Linux-RH-Edition-v1.3/chap9sec95.html)" une entrée DNS comme suit : [VOTRE IP] mqtt.idtlive.com 
