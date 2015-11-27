/**
**	Vixen Engine
**	Copyright(c) 2015 Matt Guerrette
**
**	GNU Lesser General Public License
**	This file may be used under the terms of the GNU Lesser
**  General Public License version 3 as published by the Free
**  Software Foundation and appearing in the file LICENSE.LGPLv3 included
**  in the packaging of this file. Please review the following information
**  to ensure the GNU Lesser General Public License requirements
**  will be met: https://www.gnu.org/licenses/lgpl.html
**
**/


#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <string>

#include <vix_filemanager.h>
#include <vix_inireader.h>
#include <vix_iniwriter.h>
#include <vix_debugutil.h>
#include <vix_game.h>

using namespace Vixen;

int main(int argc, char* argv[])
{
    FileManager::Initialize();
    INIReader* _reader = new INIReader;
    INIWriter* _writer = new INIWriter;

    File* file = FileManager::OpenFile("test.ini", FileMode::ReadBinary);
    if(file)
    {
        _reader->Load(file->Handle());

    }
    FileManager::CloseFile(file);


    _writer->Write("test2.ini");

    //DebugPrintF("Width: %d", _reader->GetValue<int>("TEST_SECTION", "iWidth", 50));

    _reader->PrintValues();

    FileManager::DeInitialize();

    Vixen::Game _game;


    return _game.Run();
}
