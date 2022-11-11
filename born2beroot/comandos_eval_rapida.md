## Aquí dejo solo los comandos a introducir en consola para cada comprobación de la evaluación, sin explicaciones ni más info

- Signatures `shasum born2beroot.vdi`

- UFW `sudo ufw status` o `sudo systemctl status ufw`

- SSH `sudo ssh status` o `sudo systemctl status ssh`

- Hostname `hostnamectl | grep Opertaing`

- Grupos de usuario `groups <user_name>`

- Nuevo usuario `sudo adduser <new_user>`

- Contraseñas `sudo nano /etc/login.defs` y `sudo nano /etc/pam.d/common-password`

- Nuevo grupo `sudo groupadd evaluating`, `sudo adduser <new_user> evaluating` y `groups <new_user>`

- Cambio hostname `sudo hostnamectl set-hostname <new_hostname>`

- Particiones `lsblk`

- Sudo usuario nuevo `sudo adduser <new_user> sudo`

- Sudo config y log `sudo nano etc/sudoers.d/sudo_config` y `sudo tail /var/log/sudo/<logfile>`

- UFW pruebas `sudo ufw status`, `sudo ufw allow 8080` y `sudo ufw delete allow 8080`

- SSH pruebas `sudo apt -qq -list ssh`, `sudo grep Port /etc/ssh/sshd_config`, `ssh root@localhost -p 4242` y `ssh <new_user>@localhost -p 4242`

- Script `sudo nano /usr/local/bin/monitoring.sh`, `sudo crontab -u root -e`, `sudo systemctl stop cron`

- Bonus `lsblk`, en navegador: `localhost`, en equipo externo: `ftp <ip_number>`