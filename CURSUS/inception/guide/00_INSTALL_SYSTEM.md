# Installing Linux OS in VM with Virtualbox 

### About this step

The original guide that this translation follows uses a light version of debian without "native" GUI, but in my case, I did install Debian with GUI, as we need to use a web browser within the VM during the evaluation, so I find this way simpler. 

Also, some of the following steps may differ from what you get while installing the OS in your VM, depeding on the OS that you chose, but the important thing is to know the minimum or recommended hardware settings for your VM.

## Step 1. Download

Go to https://www.debian.org and download the ISO image for the OS.

## Step 2. Launch

### 2.1 Creating a virtual machine

Create a virtual machine. We call our project something (I just called it 'inception') and set the correct system configuration. If the project is being done on a 42 School device, its folder should be placed in sgoinfre:

![virtualbox setup](media/install_debian/install_step_1.png )

![virtualbox setup](media/install_debian/install_step_1-1.png )

### 2.2 Resources setting

RAM for the project can be allocated from 512MB (if your PC has 4 GB RAM) to 4096MB (if your device has 16GB or even more RAM). It is pointless to allocate more than 4 GB of memory for this project. Also you can add more cores, but there is not real need to do so:

![virtualbox setup](media/install_debian/install_step_2.png )

The format we choose is VDI or VHD (newer versions of VBox won't ask for this), and we allocate between 8 and 12 GB for the disk:

![virtualbox setup](media/install_debian/install_step_3.png)

Also, do not forget to set a convenient screen resolution (zoom level) if you are working on MAC you will need 200-300%, for Linux system about 120-150% seems to be fine:

## Step 3. Installation

### 3.1 Start of installation

After all the settings, we launch our project. At the start, we are greeted by the installation menu. I choose a regular "auto" installer, but if desired, you can use use a more customized installation, set partitions size, etc. (In my case, I have no problems at all or any need to customize partitions or installation; the simpler the better)

![installation](media/install_debian/install_step_7.png)

### 3.2 Language and location selection

We can choose any language, keyboard input and location, as we feel more comfortable:

![language and location](media/install_debian/install_step_8.png)

![language and location](media/install_debian/install_step_9.png)

![language and location](media/install_debian/install_step_10.png)

![language and location](media/install_debian/install_step_11.png)

![language and location](media/install_debian/install_step_12.png)

![language and location](media/install_debian/install_step_13.png)

### 3.3 Configure host and users

Next, the system will prompt you to select a hostname. You can name the host inception, but I left the default name ``debian``:

![hostname](media/install_debian/install_step_14.png)

We skip the domain name, leaving the line empty.

The system will prompt us to set the password of the superuser (root). I assign Root a simple password, the number `2`.

Next, we will be asked to name an ordinary user somehow. I enter my nickname in the intro:

![user name](media/install_debian/install_step_15.png)

I accept the same name as the account name and enter a simple password.

### 3.4 Setting up Time zones

Choose your time zone.

![time zone](media/install_debian/install_step_16.png)

### 3.5 Disk Layout

Next, the markup program will start. We don't have to go into the details of the linux file system, so we choose ``use entire disk`` to use the entire disk.

![disk layout](media/install_debian/install_step_17.png)

We select the only virtual disk available to us:

![disk layout](media/install_debian/install_step_18.png)

Choose to store all files in one partition.:

![disk layout](media/install_debian/install_step_19.png)

And we give the command to complete the markup and write the changes to disk.:

![disk layout](media/install_debian/install_step_20.png)

We confirm the seriousness of our intentions:

![disk layout](media/install_debian/install_step_21.png)

### 3.6 Installing the base system

![system installation](media/install_debian/install_step_22.png)

After the markup, the installation of the base system will start. Next, I will describe only those steps that are important to us, the rest of the steps can be skipped by pressing `enter`

We just skip all the extra stuff like an additional CD image, choosing repository mirrors, or polling the popularity of packages.

### 3.6.1 Software Selection

We only need an ssh server, so we use a space to uncheck everything else. Later, we will install a lighter openbox as a graphical environment. We will only need it to open our website. We also don't need system utilities.

![system installation](media/install_debian/install_step_23.png)

### 3.6.1 Software Selection

Eventually, the system will finally tell us that it wants to install the system loader on the main partition.:

![system installation](media/install_debian/install_step_24.png)

Select a section (we have only one):

![system installation](media/install_debian/install_step_25.png)

And the installation is completed:

![system installation](media/install_debian/install_step_26.png)

We accept the offer to finish the installation:

![system installation](media/install_debian/install_step_27.png)

This is how our system is installed. Let's move on to the next guide and roll out all the software we need!