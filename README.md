# uhclspacerobo
# Erik Hitt, Sean Graham
# d240 lab sim setup

Step 1:

	set up your .bashrc file with:

		echo "source /opt/ros/kinetic/setup.bash" >> ~/.bashrc
		source ~/.bashrc

Step 2:

	set up your SwarmBaseCode directory:

		cd ~
  		git clone https://github.com/BCLab-UNM/SwarmBaseCode-ROS.git SwarmBaseCode-ROS
  		cd SwarmBaseCode-ROS

Step 3:

	set up ublox:

		git submodule init
  		git submodule update

Step 4:

	If you build it they will come:

		catkin build

Step 5:

	Change permissions for the executable and run it:

		cd ~/SwarmBaseCode-ROS
  		chmod +x ./run.sh
		./run.sh

	Run a small sim just to make sure nothing weird is going on.

Step 6

	Get the behavioral code implemented:

		cd ~/SwarmBaseCode-ROS/src/behaviours/src
		rm *
		git init
		git pull https://github.com/hittegit/uhclspacerobo.git
		cd ~/SwarmBaseCode-ROS/
		catkin build

It is complete.
