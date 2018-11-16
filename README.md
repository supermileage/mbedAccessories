## Installation

First, install `virtualenv `, which allows you to isolate python environments:

```sh
$ pip install virtualenv
```

Next, create a virtual environment

```sh
$ virtualenv mbedCan
```

Enter that virtualenv

```sh
$ source mbedCan/bin/activate
```

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

Then install the debugging server
```sh
$ pip install -U pyocd
```

Now open the project in VSCode, and go the launch.json. Change the 2 lines with the comment 'CHANGE', to the location of your 'arm-none-eabi-gdb' and 'pyocd-gdbserver' 

You should be able to plug in the LPC1768 and debug. Please read the comments about breakpoints and wait() at the top of main.cpp

