#include <shinobi.h>
#include "sndutls.h"

void UserVBlankIn(void);
void SoundMain(const PDS_PERIPHERAL *);
void setpan(Sint8 *, Sint8);
void main(void);

void UserVBlankIn() 
{
  /* Call Sound Server */
  sdSysServer();
}

void LoadMLTFile(const char* MltName) 
{
	SDMEMBLK       mem_blk;
	GDFS           fd;
	char* mlt;
	Sint32         mlt_size;
	Uint32         size;
	sdMemBlkCreate(&mem_blk);
	{
		if ((fd = gdFsOpen(MltName, NULL)) != NULL) {
			{
				gdFsGetFileSize(fd, &mlt_size);
				size = AttachSector(mlt_size);
				mlt = (char*)syMalloc(size * sizeof(char));
				gdFsRead(fd, size / GDD_FS_SCTSIZE, mlt);
				sdMemBlkSetPrm(mem_blk, mlt, mlt_size, SDD_MEMBLK_SYNC_FUNC, NULL);
				sdMultiUnitDownload(mem_blk);
			}
			gdFsClose(fd);
		}
		else PrgStop();
	}
	sdMemBlkDestroy(mem_blk);
	syFree(mlt);
}

Sint16 GetSequenceSpeed(char* BankFilename, Uint8 bank_id, Uint8 sequence_id)
{
	if (bank_id == 0 && sequence_id == 0) return 0;
	if (BankFilename == "CASINOPOLIS.MLT")
	{
		if (bank_id == 1 && sequence_id == 0) return 0;
	}
	if (BankFilename == "P_E102.MLT")
	{
		if (bank_id == 3 && sequence_id < 5) return 0;
		
	}
	if (BankFilename == "MYSTICRUIN.MLT")
	{
		if (bank_id == 1 && sequence_id == 0) return 0;
		if (bank_id == 5 && sequence_id == 0) return 0;
	}
	if (BankFilename == "SKYDECK.MLT")
	{
		if (bank_id == 1 && sequence_id == 0) return 0;
	}
	if (BankFilename == "SKYDECK_E.MLT")
	{
		if (bank_id == 1 && sequence_id == 0) return 0;
	}
	if (BankFilename == "EGGCARRIER.MLT")
	{
		if (bank_id == 1 && sequence_id == 0) return 0;
		if (bank_id == 1 && sequence_id == 1) return 0;
		if (bank_id == 1 && sequence_id == 21) return 0;
		if (bank_id == 5 && sequence_id == 0) return 0;
	}
	if (BankFilename == "E101.MLT")
	{
		if (bank_id == 5 && sequence_id == 0) return 0;
	}
	if (BankFilename == "E101R.MLT")
	{
		if (bank_id == 5 && sequence_id == 0) return 0;
	}
	if (BankFilename == "MOBILE1.MLT")
	{
		if (bank_id == 5 && sequence_id == 0) return 0;
	}
	if (BankFilename == "MOBILE2.MLT")
	{
		if (bank_id == 5 && sequence_id == 0) return 0;
	}
	if (BankFilename == "MOBILE3.MLT")
	{
		if (bank_id == 5 && sequence_id == 0) return 0;
	}
	if (BankFilename == "SKYDECK.MLT")
	{
		if (bank_id == 5 && sequence_id == 0) return 0;
	}
	if (BankFilename == "SKYDECK_E.MLT")
	{
		if (bank_id == 5 && sequence_id == 0) return 0;
	}
	if (BankFilename == "SHOOTING.MLT")
	{
		if (bank_id == 5 && sequence_id == 0) return 0;
	}
	if (BankFilename == "TWINKLEPARK.MLT")
	{
		if (bank_id == 1 && sequence_id == 0) return 0;
		if (bank_id == 1 && sequence_id == 1) return 0;
	}
	if (BankFilename == "XMAS98.MLT") return 0;
	if (BankFilename == "KADOMATSU.MLT") return 0;
	if (BankFilename == "E_0001.MLT")
	{
		if (bank_id == 6 && sequence_id == 8) return 0;
	}
	if (BankFilename == "E_000D.MLT")
	{
		if (bank_id == 6 && sequence_id == 14) return 0;
	}
	if (BankFilename == "E_001E.MLT")
	{
		if (bank_id == 6 && sequence_id == 8) return 0;
	}
	if (BankFilename == "E_00BF.MLT")
	{
		if (bank_id == 6 && sequence_id == 8) return 0;
	}
	if (BankFilename == "E_00C5.MLT")
	{
		if (bank_id == 6 && sequence_id == 8) return 0;
	}
	if (BankFilename == "E_00D4.MLT")
	{
		if (bank_id == 6 && sequence_id == 0) return 0;
	}
	return -4000;
}

Sint8 GetEffectValue(char* BankFilename, Uint8 bank_id, Uint8 sequence_id)
{
	if (bank_id == 4 && sequence_id == 1) return 0;
	if (BankFilename == "CASINOPOLIS.MLT")
	{
		if (bank_id == 1 && sequence_id == 24) return 0;
	}
	if (BankFilename == "CHAOS0.MLT")
	{
		if (bank_id == 1 && sequence_id == 3) return 0;
		if (bank_id == 5 && sequence_id == 4) return 0;
	}
	if (BankFilename == "CHAOS2.MLT")
	{
		if (bank_id == 1 && sequence_id == 3) return 0;
		if (bank_id == 5 && sequence_id == 4) return 0;
	}
	if (BankFilename == "CHAOS4.MLT")
	{
		if (bank_id == 1 && sequence_id == 17) return 0;
		if (bank_id == 5 && sequence_id == 4) return 0;
	}
	if (BankFilename == "CHAOS6.MLT")
	{
		if (bank_id == 1 && sequence_id == 3) return 0;
		if (bank_id == 1 && sequence_id == 15) return 0;
		if (bank_id == 1 && sequence_id == 19) return 0;
	}
	if (BankFilename == "CHAOS7B.MLT")
	{
		if (bank_id == 1 && sequence_id == 13) return 0;
		if (bank_id == 1 && sequence_id == 14) return 0;
	}
	if (BankFilename == "DRYMOUNTAIN.MLT")
	{
		if (bank_id == 1 && sequence_id == 1) return 0;
		if (bank_id == 1 && sequence_id == 28) return 0;
		if (bank_id == 1 && sequence_id == 29) return 0;
		if (bank_id == 1 && sequence_id == 30) return 0;
	}
	if (BankFilename == "E101.MLT")
	{
		if (bank_id == 1 && sequence_id == 1) return 0;
		if (bank_id == 1 && sequence_id == 2) return 0;
		if (bank_id == 1 && sequence_id == 3) return 0;
	}
	if (BankFilename == "E101R.MLT")
	{
		if (bank_id == 1 && sequence_id == 1) return 0;
		if (bank_id == 1 && sequence_id == 10) return 0;
		if (bank_id == 1 && sequence_id == 11) return 0;
	}
	if (BankFilename == "EMERALDCOAST.MLT")
	{
		if (bank_id == 1 && sequence_id == 7) return 0;
	}
	if (BankFilename == "FINALEGG.MLT")
	{
		if (bank_id == 1 && sequence_id == 9) return 0;
	}
	if (BankFilename == "HIGHWAY.MLT")
	{
		if (bank_id == 1)
		{
			if (sequence_id == 4 || sequence_id == 13 || sequence_id == 15 || sequence_id == 16 || sequence_id == 17 || sequence_id == 18 || sequence_id == 30) return 0;
		}
	}
	if (BankFilename == "HOTSHELTER.MLT")
	{
		if (bank_id == 1 && sequence_id == 28) return 0;
		if (bank_id == 1 && sequence_id == 29) return 0;
		if (bank_id == 1 && sequence_id == 30) return 0;
	}
	if (BankFilename == "MOBILE1.MLT")
	{
		if (bank_id == 1 && sequence_id == 3) return 0;
	}
	if (BankFilename == "MOBILE3.MLT")
	{
		if (bank_id == 1 && sequence_id == 13) return 0;
	}
	if (BankFilename == "STATIONSQUARE.MLT")
	{
		if (bank_id == 1)
		{
			if (sequence_id == 18 || sequence_id == 27 || sequence_id == 28 || sequence_id == 29) return 0;
		}
	}
	if (BankFilename == "TWINKLEPARK.MLT")
	{
		if (bank_id == 1 && sequence_id == 23) return 0;
	}
	if (BankFilename == "WINDYVALLEY.MLT")
	{
		if (bank_id == 1)
		{
			if (sequence_id == 2 || sequence_id == 28 || sequence_id == 29 || sequence_id == 30) return 0;
		}
	}
	return -48;
}

void SoundMain(const PDS_PERIPHERAL* pad)
{
	SDS_MIDI_MES midi_mes;
	static int framecounter = 0;
	static bool reload = false;
	static int filechanged = 0;
	static int filesleft = 0;
	static bool play = false;
	static bool pad_pressed = false;
	static bool autoplay = true;
	static SDS_MIDI_STAT stat;
	static Uint8 playbacktimer = 0;
	static Uint32 timer2 = 0;
	static Sint8 playmode = 0; //0 - playing, 1 - next sound, 2 - waiting, 3 - next bank, 4 - next file
	static Sint8 selection = 0;
	static Sint8 bankID = 0;
	static Uint8 fileID = 0;
	static Sint8 sequenceID = 0;
	static Uint8 dspID = 0;
	static Sint8 fxLevel = -48;
	static Sint8 directLevel;
	static Sint8 volume = 0;
	static Sint16 pitch = 0;
	static Sint16 speed = 0;
	static bool fxEnable = true;
	static SDMIDI midi_handle;
	static Sint32 status = 0;
	static Uint8 numnames = 0;
	GDFS fd;
	char* msg[] = { "STOP", "PLAY", "NO DATA" };
	char* FilenameArray[] = {
		"CART.MLT",
		"CASINOPOLIS.MLT",
		"CHAOS0.MLT",
		"CHAOS2.MLT",
		"CHAOS4.MLT",
		"CHAOS6.MLT",
		"CHAOS7A.MLT",
		"CHAOS7B.MLT",
		"DRYMOUNTAIN.MLT",
		"E101.MLT",
		"E101R.MLT",
		"EGGCARRIER.MLT",
		"EMERALDCOAST.MLT",
		"FINALEGG.MLT",
		"HIGHWAY.MLT",
		"HOTSHELTER.MLT",
		"ICECAP.MLT",
		"LOSTWORLD.MLT",
		"MOBILE1.MLT",
		"MOBILE2.MLT",
		"MOBILE3.MLT",
		"MYSTICRUIN.MLT",
		"SANDHILL.MLT",
		"SHOOTING.MLT",
		"SKYDECK.MLT",
		"SKYDECK_E.MLT",
		"STATIONSQUARE.MLT",
		"TWINKLEPARK.MLT",
		"WINDYVALLEY.MLT",
		"P_AMY.MLT",
		"P_BIG.MLT",
		"P_E102.MLT",
		"P_KNUCKLES.MLT",
		"P_SONICTAILS.MLT",
		"V_AMY.MLT",
		"V_AMY_E.MLT",
		"V_BIG.MLT",
		"V_BIG_E.MLT",
		"V_E102.MLT",
		"V_E102_E.MLT",
		"V_KNUCKLES.MLT",
		"V_KNUCKLES_E.MLT",
		"V_SONICTAILS.MLT",
		"V_SONICTAILS_E.MLT",
		"QUO.MLT",
		"XMAS98.MLT",
		"KADOMATSU.MLT",
		"TARGET.MLT",
		"E_0001.MLT",
		"E_0002.MLT",
		"E_0003.MLT",
		"E_0007.MLT",
		"E_0008.MLT",
		"E_0009.MLT",
		"E_000D.MLT",
		"E_0012.MLT",
		"E_0016.MLT",
		"E_001B.MLT",
		"E_001E.MLT",
		"E_0022.MLT",
		"E_0024.MLT",
		"E_0029.MLT",
		"E_0035.MLT",
		"E_0042.MLT",
		"E_0046.MLT",
		"E_0047.MLT",
		"E_004B.MLT",
		"E_004D.MLT",
		"E_004E.MLT",
		"E_0060.MLT",
		"E_0061.MLT",
		"E_0064.MLT",
		"E_0065.MLT",
		"E_0068.MLT",
		"E_0071.MLT",
		"E_0080.MLT",
		"E_0087.MLT",
		"E_0091.MLT",
		"E_0097.MLT",
		"E_009D.MLT",
		"E_00B0.MLT",
		"E_00B7.MLT",
		"E_00BA.MLT",
		"E_00BB.MLT",
		"E_00BF.MLT",
		"E_00C5.MLT",
		"E_00D0.MLT",
		"E_00D4.MLT",
		"E_00DE.MLT",
		"E_00F3.MLT",
		"E_00F4.MLT",
		"E_00F5.MLT",
		"E_00F7.MLT",
		"E_00F8.MLT",
		"E_00FA.MLT",
		"E_00FD.MLT",
		"E_00FE.MLT",
		"E_00FF.MLT",
		"E_0160.MLT",
		"ALIFE.MLT",
		"ALIFE_AMY.MLT",
		"ALIFE_AMY_E.MLT",
		"ALIFE_BIG.MLT",
		"ALIFE_BIG_E.MLT",
		"ALIFE_E102.MLT",
		"ALIFE_E102_E.MLT",
		"ALIFE_KNUCKLES.MLT",
		"ALIFE_KNUCKLES_E.MLT",
		"ALIFE_SONIC.MLT",
		"ALIFE_SONIC_E.MLT",
		"ALIFE_TAILS.MLT",
		"ALIFE_TAILS_E.MLT",
		"ALT_E102.MLT",
		"ALT_E102_E.MLT",
		"ALT_EGGCARRIER.MLT",
		"ALT_KNUCKLES.MLT",
		"ALT_KNUCKLES_E.MLT",
		"ALT_MYSTICRUIN.MLT",
		"ALT_SONICTAILS.MLT",
		"ALT_SONICTAILS_E.MLT",
		"CASINO_AMY.MLT",
		"CASINO_AMYVOICE.MLT",
		"CASINO_BIG.MLT",
		"CASINO_BIGVOICE.MLT",
		"CASINO_E102.MLT",
		"CASINO_E102VOICE.MLT",
		"CASINO_KNUCKLES.MLT",
		"CASINO_KNUCKLESVOICE.MLT",
		"CASINO_KNUCKLESVOICE_E.MLT",
		"CASINO_SONICTAILS.MLT",
		"CASINO_SONICTAILSVOICE.MLT",
		"CASINO_SONICTAILSVOICE_E.MLT",
	};
	numnames = 131; //Actual number minus 1
	//Set the number of files left for autoplay
	if (autoplay)
	{
		if (fileID <= 28 && (bankID == 1 || bankID == 4 || bankID == 5)) filesleft = 29 - fileID;
		else if (fileID <= 33 && bankID == 3) filesleft = 34 - fileID;
		else if (fileID <= 43 && bankID == 6) filesleft = 44 - fileID;
		else if (fileID <= 98 && bankID == 6) filesleft = 99 - fileID;
		else if (bankID == 0 || bankID == 2 || bankID == 7 || bankID == 8) filesleft = 1;
		else filesleft = 0;
	}
	//Reload file
	if (reload == true)
	{
		status = 0;
		LoadMLTFile(FilenameArray[fileID]);
		reload = false;
	}
	//Start playing
	if (pad->press & PDD_DGT_ST)
	{
		play = true;
		pad_pressed = true;
	}
	if (pad_pressed)
	{
		pad_pressed = false;
		if (status == 0 || status == 2)
		{
			if (fxEnable == true)
			{
				sdSndClearFxPrg();
				sdSndSetFxPrg(dspID, 0);
			}
			else
			{
				sdSndClearFxPrg();
				sdSndSetFxOut(1);
			}
			sdMidiOpenPort(&midi_handle);
			if (autoplay) fxLevel = GetEffectValue(FilenameArray[fileID], bankID, sequenceID);
			sdMidiSetFxLev(midi_handle, fxLevel);
			sdMidiSetPitch(midi_handle, pitch, 0);
			if (autoplay) speed = GetSequenceSpeed(FilenameArray[fileID], bankID, sequenceID);
			sdMidiSetSpeed(midi_handle, speed, 0);
			sdMidiSetVol(midi_handle, volume, 0);
			sdMidiPlay(midi_handle, bankID, sequenceID, 0);
			status = 1;
			playbacktimer = 0;
			playmode = 0;
			if (bankID == 5) timer2 = 1800; 
			else if (bankID == 6 && fileID >= 48) timer2 = 1800;
			else timer2 = 600;
		}
		else
		{
			sdMidiStop(midi_handle);
			sdMidiClosePort(midi_handle);
			status = 0;
			playbacktimer = 0;
			autoplay = false;
			playmode = 0;
		}
	}
	//Change selection
	if (filechanged == 0 && pad->press & PDD_DGT_KD)
	{
		selection++;
		if (selection > 10) selection = 0;
	}
	if (filechanged == 0 && pad->press & PDD_DGT_KU)
	{
		selection--;
		if (selection < 0) selection = 10;
	}
	//Switch between common categories of MLT files
	if (pad->press & PDD_DGT_TX && selection == 0)
	{
		//0-28 are level soundbanks
		//29-43 are player P_ and V_ banks
		//48-98 are cutscene E_ banks
		//99-131 are ALIFE banks and unused ALT and CASINO stuff
		if (!filechanged && fileID >= 0 && fileID <= 28)
		{
			fileID = 29;
			filechanged = 30;
		}
		if (!filechanged && fileID >= 29 && fileID <= 47)
		{
			fileID = 48;
			filechanged = 30;
		}
		if (!filechanged && fileID >= 48 && fileID <= 98)
		{
			fileID = 99;
			filechanged = 30;
		}
		if (!filechanged && fileID >= 99)
		{
			fileID = 0;
			filechanged = 30;
		}
	}
	if (pad->press & PDD_DGT_TY && selection == 0)
	{
		if (!filechanged && fileID >= 0 && fileID <= 28)
		{
			fileID = 131;
			filechanged = 30;
		}
		if (!filechanged && fileID >= 29 && fileID <= 47)
		{
			fileID = 28;
			filechanged = 30;
		}
		if (!filechanged && fileID >= 48 && fileID <= 98)
		{
			fileID = 43;
			filechanged = 30;
		}
		if (!filechanged && fileID >= 99)
		{
			fileID = 98;
			filechanged = 30;
		}
	}
	//Decrease values 
	if (pad->press & PDD_DGT_KL || (pad->on & PDD_DGT_TB && framecounter % 8 == 0))
	{
		//File
		if (selection == 0)
		{
			fileID--;
			if (fileID > numnames) fileID = numnames;
			filechanged = 30;
		}
		//Bank ID
		if (selection == 1)
		{
			bankID--;
			if (bankID < 0) bankID = 16;
		}
		//Sequence ID
		if (selection == 2)
		{
			sequenceID--;
			if (sequenceID < 0) sequenceID = 127;
		}
		//DSP ID
		if (selection == 3)
		{
			dspID--;
			if (dspID > 16) dspID = 16;
			sdSndClearFxPrg();
			sdSndSetFxPrg(0, 0);
		}
		//DSP Off
		if (selection == 4)
		{
			fxEnable = !fxEnable;
			sdSndClearFxPrg();
			sdSndSetFxOut(1);
		}
		//Effect level
		if (selection == 5)
		{
			fxLevel--;
			sdMidiSetFxLev(midi_handle, fxLevel);
		}
		//Direct level
		if (selection == 6)
		{
			directLevel--;
			sdMidiSetDrctLev(midi_handle, directLevel);
		}
		//Volume level
		if (selection == 7)
		{
			volume--;
		}
		//Pitch level
		if (selection == 8)
		{
			if (pad->on & PDD_DGT_TB) pitch -= 100;
			else pitch--;
			sdMidiSetPitch(midi_handle, pitch, 0);
		}
		//Speed level
		if (selection == 9)
		{
			if (pad->on & PDD_DGT_TB) speed -= 100;
			else speed--;
			sdMidiSetSpeed(midi_handle, speed, 0);
		}
		//Autoplay
		if (selection == 10)
		{
			autoplay = !autoplay;
		}
	}
	//Increase values 
	if (pad->press & PDD_DGT_KR || (pad->on & PDD_DGT_TA && framecounter % 8 == 0))
	{
		//File
		if (selection == 0)
		{
			fileID++;
			if (fileID > numnames) fileID = 0;
			filechanged = 30;
		}
		//Bank ID
		if (selection == 1)
		{
			bankID++;
			if (bankID > 16) bankID = 0;
		}
		//Sequence ID
		if (selection == 2)
		{
			if (sequenceID == 127) sequenceID = 0;
			else sequenceID++;
		}
		//DSP ID
		if (selection == 3)
		{
			dspID++;
			if (dspID > 16) dspID = 0;
			sdSndClearFxPrg();
			sdSndSetFxPrg(dspID, 0);
		}
		//DSP On
		if (selection == 4)
		{
			fxEnable = !fxEnable;
			sdSndClearFxPrg();
			sdSndSetFxPrg(0, 0);
		}
		//Effect level
		if (selection == 5)
		{
			fxLevel++;
			if (fxLevel > 127) fxLevel = -128;
		}
		//Direct level
		if (selection == 6)
		{
			directLevel++;
			if (directLevel > 127) directLevel = -128;
			sdMidiSetDrctLev(midi_handle, directLevel);
		}
		//Volume level
		if (selection == 7)
		{
			volume++;
		}
		//Pitch level
		if (selection == 8)
		{
			if (pad->on & PDD_DGT_TA) pitch += 100;
			else pitch++;
			sdMidiSetPitch(midi_handle, pitch, 0);
		}
		//Speed level
		if (selection == 9)
		{
			if (pad->on & PDD_DGT_TA) speed += 100;
			else speed++;
			sdMidiSetSpeed(midi_handle, speed, 0);
		}
		//Autoplay
		if (selection == 10)
		{
			autoplay = !autoplay;
			play = false;
		}
	}
	//Reset values
	if (pad->on & PDD_DGT_TL || pad->on & PDD_DGT_TR)
	{
		//File
		if (selection == 0 && (pad->on & PDD_DGT_TL))
		{
			fileID = 0;
			sdMidiStop(midi_handle);
			sdMidiClosePort(midi_handle);
			reload = true;
		}
		if (selection == 0 && (pad->on & PDD_DGT_TR))
		{
			fileID = numnames;
			sdMidiStop(midi_handle);
			sdMidiClosePort(midi_handle);
			reload = true;
		}
		//Bank ID
		if (selection == 1)
		{
			bankID = 0;
		}
		//Sequence ID
		if (selection == 2)
		{
			sequenceID = 0;
		}
		//DSP ID
		if (selection == 3)
		{
			dspID = 0;
			sdSndClearFxPrg();
			sdSndSetFxPrg(dspID, 0);
		}
		//DSP Off
		if (selection == 4)
		{
			fxEnable = false;
			sdSndClearFxPrg();
			sdSndSetFxOut(1);
		}
		//Effect level
		if (selection == 5 && (pad->on & PDD_DGT_TL))
		{
			fxLevel = -48;
		}
		if (selection == 5 && (pad->on & PDD_DGT_TR))
		{
			fxLevel = 0;
		}
		//Direct level
		if (selection == 6)
		{
			directLevel = 0;
		}
		//Volume level
		if (selection == 7)
		{
			volume = 0;
		}
		//Pitch level
		if (selection == 8)
		{
			pitch = 0;
			sdMidiSetPitch(midi_handle, pitch, 0);
		}
		//Speed level
		if (selection == 9 && (pad->on & PDD_DGT_TL))
		{
			speed = -4000;
			sdMidiSetSpeed(midi_handle, speed, 0);
		}
		if (selection == 9 && (pad->on & PDD_DGT_TR))
		{
			speed = 0;
			sdMidiSetSpeed(midi_handle, speed, 0);
		}
		//Autoplay
		if (selection == 10)
		{
			autoplay = 0;
			play = false;
		}
	}
	//Load MLT file after releasing the buttons
	if (filechanged > 0 && filechanged >= 2) filechanged--;
	if (filechanged > 0 && filechanged < 2)
	{
		if (!(pad->press & PDD_DGT_KR || pad->on & PDD_DGT_TA) && !(pad->press & PDD_DGT_KL || pad->on & PDD_DGT_TB) && !(pad->press & PDD_DGT_KR || pad->on & PDD_DGT_TA))
		{
			sdMidiStop(midi_handle);
			sdMidiClosePort(midi_handle);
			reload = true;
			filechanged = 0;
		}
	}
	framecounter++;
	if (framecounter > 6000) framecounter = 0;
	//Background color
	if (!autoplay || !play) njSetBackColor(0x00000000, 0x00000000, 0x000000FF); //Normal
	else
	{
		if (filesleft > 10) njSetBackColor(0x00000000, 0x00000000, 0x0000FF00); //Green
		else if (filesleft > 5) njSetBackColor(0x00000000, 0x00000000, 0x00FFFF00); //Yellow
		else if (filesleft > 0) njSetBackColor(0x00000000, 0x00000000, 0x00FF0000); //Red
		else
		{
			njSetBackColor(0x00000000, 0x00000000, 0x00000000); //Black
			sdMidiStop(midi_handle);
			sdMidiClosePort(midi_handle);
			status = 0;
			timer2 = 0;
			playmode = 0;
		}
	}
	njPrintColor(0xCC30F030);
	njPrintC(NJM_LOCATION(1, 5 + selection), ">");
	njPrintColor(0xCCC0C0C0);
	njPrint(NJM_LOCATION(2, 5), "FILE    : %s", FilenameArray[fileID]);
	njPrint(NJM_LOCATION(2, 6), "BNK ID  : %03d", bankID);
	njPrint(NJM_LOCATION(2, 7), "SEQ ID  : %03d", sequenceID);
	njPrint(NJM_LOCATION(2, 8), "FX  ID  : %03d", dspID);
	njPrint(NJM_LOCATION(2, 9), "FX  ON  : %01d", fxEnable);
	njPrint(NJM_LOCATION(2, 10), "FX LVL  : %03d", fxLevel);
	njPrint(NJM_LOCATION(2, 11), "DIR LVL : %03d", directLevel);
	njPrint(NJM_LOCATION(2, 12), "VOLUME  : %03d", volume);
	njPrint(NJM_LOCATION(2, 13), "PITCH   : %05d", pitch);
	njPrint(NJM_LOCATION(2, 14), "SPEED   : %05d", speed);
	njPrint(NJM_LOCATION(2, 15), "AUTOPLAY: %01d", autoplay);
	if (autoplay)
	{
		njPrint(NJM_LOCATION(2, 17), "TIMER   : %d", timer2);
		njPrint(NJM_LOCATION(2, 18), "LEFT    : %d", filesleft);
	}
	njPrintC(NJM_LOCATION(2, 20), "STATUS  :");
	njPrintC(NJM_LOCATION(2, 21), "FLAGS   :");
	sdMidiGetStat(midi_handle, &stat);
	njPrintColor(0xCCC0C0C0);
	njPrintH(NJM_LOCATION(12, 21), stat.m_Flg, 8);
	//Get flags and set status
	if (play)
	{
		if (timer2 > 0) timer2--;
		if (status == 1)
		{
			playbacktimer++;
		}
		if (stat.m_Flg & SDD_PORT_FLG_PLAY) njPrintColor(0xCC30F030); //Normal
		else //End playing
		{
			if (autoplay && status == 1 && playbacktimer > 10)
			{
				status = 0;
				sdMidiStop(midi_handle);
				sdMidiClosePort(midi_handle);
				timer2 = 240;
				playmode = 2;
			}
		}
		//No data
		if (stat.m_Flg & SDD_PORT_FLG_TROUBLE)
		{
			if (autoplay && timer2 <= 0)
			{
				/*if (bankID < 7) //Next bank
				{
					sequenceID = 0;
					bankID++;
					if (bankID == 0) bankID = 1; //Skip bank 0 (common)
					if (bankID == 2) bankID = 3; //Skip bank 2 (check sheet)
					if (bankID == 4) bankID = 5; //Skip bank 4 (enemy)
					status = 0;
					sdMidiStop(midi_handle);
					sdMidiClosePort(midi_handle);
					timer2 = 60;
					playmode = 2;
				}
				else //Next file
				{*/
					sequenceID = 0;
					//bankID = 1; //Skip bank 0 (common)
					status = 0;
					sdMidiStop(midi_handle);
					sdMidiClosePort(midi_handle);
					fileID++;
					reload = true;
					timer2 = 120;
					playmode = 3;
				//}
			}
			else
			{
				status = 2;
				njPrintColor(0xCCF0F030);
			}
		}
		//Stopped
		if (status == 0)
		{
			njPrintColor(0xCCF03030);
		}
		njPrintC(NJM_LOCATION(12, 20), msg[status]);
		//Playmode stuff
		if (autoplay && playmode == 0 && timer2 <= 0) //Waiting mode
		{
			sdMidiStop(midi_handle);
			sdMidiClosePort(midi_handle);
			status = 0;
			timer2 = 120;
			playmode = 2;
		}
		if (autoplay && playmode == 2 && timer2 <= 0) playmode = 1; //End waiting
		if (autoplay && playmode == 3 && timer2 <= 0) //Next file mode
		{
			sdMidiStop(midi_handle);
			sdMidiClosePort(midi_handle);
			status = 0;
			playmode = 0;
			if (autoplay) pad_pressed = true;
		}
		if (autoplay && playmode == 1) //Next sequence
		{
			sdMidiStop(midi_handle);
			sdMidiClosePort(midi_handle);
			status = 0;
			playmode = 0;
			if (autoplay)
			{
				sequenceID++;
				pad_pressed = true;
			}
		}
	}
}
 
void main(void)
{
  Int            y = 0, x = 0;
  static Sint32  i = 0;
  const PDS_PERIPHERAL *pad;

#ifdef __GNUC__
	shinobi_workaround();
#endif
  /* Initialize System */
  njSetBorderColor( 0x00000000 );

  sbInitSystem(NJD_RESOLUTION_VGA, NJD_FRAMEBUFFER_MODE_RGB565, 1);

  njInitVertexBuffer( 20000, 0, 20000, 0, 0 );
  njInitPrint( NULL, 0, NJD_TEXFMT_ARGB_1555 );

  SoundInitialize( "MANATEE.DRV", "CART.MLT");

  njSetVSyncFunction( UserVBlankIn );

  while ( 1 ) {
    pad = pdGetPeripheral( PDD_PORT_A0 );
	SoundMain(pad);
	njPrintColor(0xCCC0C0C0);
	njPrintSize(16);
	njPrintC(NJM_LOCATION(11, 2), "-- Sequence Test --");
    njWaitVSync();
  }
}

/******************************* end of file *******************************/
