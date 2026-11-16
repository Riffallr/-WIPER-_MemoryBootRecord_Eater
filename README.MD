About the Project
MBR-Eater is a simple Windows GUI application written in C++ using pure Win32 API. It demonstrates how a regular application can gain access to a physical disk (\\.\PhysicalDrive0) and overwrite the first 512 bytes (the Master Boot Record), rendering the operating system unbootable.

The project exists to show why antiviruses and security systems (like Secure Boot or UAC) matter, and how easily a system can be bricked when administrator privileges are available.

??? Technical Details
Language: C++ (Win32 API)

Interface: Windowed application (GUI)

Features:
Creates a window with a custom design.
Button linking to the author's GitHub and YouTube (Source + Subscribe).
"Start destroying MBR" button, which:

Opens the physical disk PhysicalDrive0 with GENERIC_ALL flags.
Writes 512 zero bytes (MBR_SIZE) to the beginning of the disk.
Changes the window background to black (visual effect).

?? Build and Run

Requirements:
Microsoft Visual Studio (2019 or 2022 recommended).
Windows SDK.
A virtual machine (strongly recommended).

Run:

    ALWAYS run as administrator.
    ALWAYS run only in a virtual environment.

?? Important Disclaimer
The author is not responsible for any damage caused to your system, data, or hardware. The code is provided "as is" for educational purposes. Using this code to attack systems you do not own is illegal.

?? Links
GitHub: https://github.com/Riffallr
YouTube: @RiffallRRR
