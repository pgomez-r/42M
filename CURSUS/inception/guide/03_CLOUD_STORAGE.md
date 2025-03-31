# Project storing and portability

When working on a project, you may need to transfer the configuration to another computer. This may seem pointless if you can do everything on the same PC and do not worry. But if that is not the case, the portability of the project becomes a very useful feature, so it is important to think and plan it from the beginning.

In my case, I develop and run the project in a USB stick formatted in ext4 -only usable on Linux distributions-. I created the VM there from the beginning when using VBox installation wizard, but you could also copy all files into it if you created the VM on your device or the school sgoinfre previously.

Working on a external memory is quite easy and convenient, but I found some issues -due to my own lack of knowledge- so let me point some tips in case it may help you to avoid some headaches:

> TIP #1: It is strongly recommended to always use the same exact version of VirtualBox when doing so. Otherwise, you may face several compatibilty problems. Version 7.0.18 is the current version installed in 42 Málaga as I write this guide (27/02/2025).

> TIP #2: ANY TIME YOU FINISH WORKING, SHUTDOWN THE VM PROPERLY (using commmand `sudo shutdown now` or using VBox interface option), DO NOT USE 'SAVE CURRENT STATE'. Saving state only lets you relaunch the machine again in the same host machine that you saved when quitting, so that won't work if you want to work in different devices!

> TIP #3: Depending on the file system format of your memory device and/or the version of VBox you are using, you may find that any time you launch the VM, VBox changes the permissions of the .vbox files to only root. This may be problematic if you are not root or superuser on the next device you try to launch the VM again -which will happen in 42, most likely- so take into consideration.

In case you want or need to use an alternative way, the reference guide explains how to store the project on the cloud, so I also let that info here.

## Step 1. Learn how to create snapshots

No matter the method you use to keep your files save, something you do need to learn is how to create snapshots of the system state, and save the system with them. Let's start with that.

A snapshot is like a photograph of the system status; it's like saving in a videogame. Just as in a game you should not move to the next boss fight without saving, in the inception project you should not do rush actions without snapshots. If something goes wrong, the system can be rolled back to the previous snapshot.

> Attention! The virtual machine must be turned off to create the snapshot!

Go to virtualbox and go to the "snapshots" menu.

![snapshot menu](media/saving_snapshots/step_0.png)

From above, click on the green plus sign with the inscription "make" and describe our changes.

![Creating snapshots](media/saving_snapshots/step_1.png)

This way we get a snapshot of our current changes.:

![Creating snapshots](media/saving_snapshots/step_2.png)

If something goes wrong, it will not be necessary to delete and redo the configuration, you can simply roll back to the previous working configuration.

## Step 2. Find the installed configuration

Go to the folder on goinfre where our configuration is stored. If we look at the file sizes, we will find that the disk .A vhd weighs more than 2 gigabytes (in my case, almost three gigs), and most modern cloud storage does not support files larger than two gigabytes.

![configuration search](media/configuration_storage/step_0.png)

## Step 3. Compress large files

There is a way out! ~~It is necessary to compress the file through the input .vhd and folders. Now our disk weighs 950 megabytes instead of 3 gigabytes!

![file compression](media/configuration_storage/step_1.png)

![file compression](media/configuration_storage/step_2.png)

## Step 4. Upload files to the cloud

![cloud storage](media/configuration_storage/step_3.png)

This configuration weighs only 1.38 GB with snapshots. Now it can be downloaded and deployed on any school mac and even on a home PC.

For the subsequent transfer, you will need to make a new snapshot after all the saved changes, compress the files and upload them to the cloud again.

## Step 5. Running the configuration on another school mac

> (!) This step is no longer needed in 42Málaga, as we don't use MacOS anymore, plus we do store our large files or projects in sgoingfre, but I will keep the info here just in case it can be useful for other students or in different cases

If we log in to another computer, we regret to find that there is nothing from goinfree on it, and our configuration is missing.:

![cloud storage](media/configuration_storage/step_4.png)

To save files, we will most likely have to slightly change the browser settings.:

![cloud storage](media/configuration_storage/step_5.png)

We download our configuration from the cloud to goinfree and create a folder that is named the same as the folder of our previous configuration at the previous location:

![cloud storage](media/configuration_storage/step_6.png)

Let's unzip all our archives and get the following:

![cloud storage](media/configuration_storage/step_7.png)

Go to virtualbox and see that our configuration is working.:

![cloud storage](media/configuration_storage/step_8.png)

And for deployment on a home PC/On the laptop, we will need to download and unzip the configuration, and then in the virtualbox "Tools" tab, click on the green "Add" icon, specifying the folder with the Debian file.vbox and other files.