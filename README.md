## Installation (for mac)

First, install `virtualenv`, which allows you to isolate python environments:

```sh
$ pip install virtualenv
```

Next, create a virtual environment

```sh
$ virtualenv mbedCanEnv
```

Enter that virtualenv

```sh
$ source mbedCanEnv/bin/activate
```

Then add the virtualenv bin to PATH
```sh
$ sudo nano /etc/paths
```
And add the location of `bedCanEnv/bin` (can find this with `pwd` command in the directory)

You can leave this environment at any point with

```sh
$ deactivate
```

Now install the mbed command line interface in that your virtualenv (mbed-cli)
```sh
$ pip install mbed-cli
```

Then clone the repo
```sh
$ git clone https://github.com/supermileage/mbedCanbus
```

Navigate into the repo and run the following command to install the mbed libraries
```sh
$ mbed update master 
```

Navigate to mbed-os folder, and run
```sh
$ pip install -r requirements.txt
```

Install the pyOCD which is our debugging server
```sh
$ pip install -U pyocd
```

Install the arm toolchain arm-none-eabi-gdb
```sh
$ brew tap ArmMbed/homebrew-formulae
$ brew install arm-none-eabi-gcc
```

Now open the project in VSCode, and go the launch.json. Change the 2 lines with the comment 'CHANGE', to the location of your 'arm-none-eabi-gdb' and 'pyocd-gdbserver' 

You should be able to plug in the LPC1768 and debug. Please read the comments about breakpoints and wait() at the top of main.cpp

