import sys
from os.path import basename
import pprint
import textwrap


class Converter:
    """can convert from letter notes in the format of
    https://pianoletternotes.blogspot.com to the format
    useful to make it play back on Arduino
    """

    def __init__(self, name, tabtext):
        self.name = name
        self.tabtext = tabtext

    def getNotes(self):
        lines = self.tabtext.split('\n')
        if len(lines) == 0:
            return []

        notes = []
        currnote = None
        currlen = None

        for linepair in self.grouper(lines):
            right_hand_line = linepair[0]
            if len(right_hand_line) == 0:
                continue

            if len(linepair[1]) > 0:
                left_hand_line = linepair[1]
            else:
                left_hand_line = self._emptyLine(len(right_hand_line) - 3) 

            octave_right = int(right_hand_line[0])
            octave_left = int(left_hand_line[0])

            for i, right_hand_char in enumerate(right_hand_line[2:]):
                left_hand_char = left_hand_line[i+2]

                if right_hand_char == '-' and left_hand_char == '-':
                    # previous note held
                    if currlen:
                        currlen = currlen + 1
                elif right_hand_char == '|':
                    pass # end of line, nothing to do
                else:
                    # we have a new on the right-hand or left-hand line
                    if currnote:
                        notes.append((currnote, currlen))

                    if right_hand_char != '-':
                        currnote = self._mapToNote(octave_right, right_hand_char)
                    else:
                        currnote = self._mapToNote(octave_left, left_hand_char)

                    currlen = 1

        if currnote:
            notes.append((currnote, currlen))

        return notes

    def grouper(self, lines):
        lineID = 0
        while lineID < len(lines):
            # skip empty lines
            if lines[lineID] == "":
                lineID = lineID + 1
                continue
            # return the last line by itself
            if lineID == (len(lines) - 1):
                yield [lines[lineID], ""]
                break
            # return one-handed lines by themselves and skip the empty line
            if lines[lineID + 1] == "":
                yield [lines[lineID], ""]
                lineID = lineID + 2
            else:
                # return two-handed lines together and skip the following line
                yield [lines[lineID], lines[lineID + 1]]
                lineID = lineID + 3

    def _emptyLine(self, length):
        return "0|" + ("-" * length) + "|" 

    def _mapToNote(self, octave, char):
        return "NOTE_%s%s%d" % \
            (char.upper(),
            "S" if char.isupper() else "", 
            octave)
    
    def printCode(self):
        notes = self.getNotes()
        self._printNotes(notes)
        self._printTempos(notes)
    
    def _printNotes(self, notes):
        self._printNotesPart(notes, "notes", 0)

    def _printTempos(self, notes):
        self._printNotesPart(notes, "tempos", 1)

    def _printNotesPart(self, notes, partString, partID):
        print("int %s_%s[] = {" % (self.name, partString))
        for line in textwrap.wrap(", ".join(map(lambda x: str(x[partID]), notes)),
                                  width=70, break_long_words=False,
                                  initial_indent='  ', subsequent_indent='  '):
            print(line) 
        print("};")        
            



if __name__ == '__main__':
    if len(sys.argv) == 1:
        print("Usage: " + sys.argv[0] + " <filename>")
        exit(1)
    filename = sys.argv[1]
    songname = basename(filename).split('.', 1)
    songname = songname[0]
    converter = Converter(songname, open(filename).read(10000))
    
    converter.printCode()
