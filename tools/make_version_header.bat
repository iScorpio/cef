@echo off
python.bat tools\make_version_header.py --header include\cef_version.h --cef_version VERSION.in --chrome_version ../chrome/VERSION --cpp_header_dir include
