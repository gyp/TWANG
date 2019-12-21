from converter import *

def test_empty_doc_should_return_empty_notes():
    c = Converter("testtab", "")
    assert c.getNotes() == []

def test_single_note_in_a_line_should_return_a_one_element_list_for_notes():
    notes = get_notes_for_tabstring("4|a-------------------------|")
    assert isinstance(notes, list)
    assert len(notes) == 1

def get_notes_for_tabstring(tabstring):
    c = Converter("testtab", tabstring)
    return c.getNotes()    

def test_single_a_note_should_have_the_correct_pitch():
    notes = get_notes_for_tabstring("4|a-------------------------|")
    (pitch, _) = notes[0]
    assert pitch == "NOTE_A4"

def test_single_note_should_have_the_proper_octave():
    for octave in range(9):
        notes = get_notes_for_tabstring("%d|a-------------------------|" % octave)
        (pitch, _) = notes[0]
        assert int(pitch[-1:]) == octave

def test_two_notes_in_a_line_should_result_in_two_converted_notes():
    notes = get_notes_for_tabstring("4|aa------------------------|")
    assert len(notes) == 2

def test_two_notes_in_a_line_should_both_have_the_right_pitch():
    notes = get_notes_for_tabstring("4|ac------------------------|")
    (pitch, _) = notes[0]
    assert pitch == "NOTE_A4"
    (pitch, _) = notes[1]
    assert pitch == "NOTE_C4"

def test_first_note_from_two_consecutive_notes_should_have_the_length_of_one():
    notes = get_notes_for_tabstring("4|ac------------------------|")
    (_, length) = notes[0]
    assert length == 1

def test_note_length_should_be_the_space_before_next_note():
    for notegap in range(10):
        tabstring = "4|a" + ("-" * notegap) + "c|"
        notes = get_notes_for_tabstring(tabstring)
        (_, length) = notes[0]
        assert length == notegap + 1

def test_uppercase_notes_should_be_sharps():
    for note in "CDFGAC":
        notes = get_notes_for_tabstring("4|%s---|" % note)
        (pitch, _) = notes[0]
        assert pitch == "NOTE_%sS4" % note 

def test_two_notes_in_multiple_separate_lines_should_result_in_two_notes():
    tabstring = '''
4|a-----------------|

4|b-----------------|
'''[1:-1]
    notes = get_notes_for_tabstring(tabstring)
    assert len(notes) == 2

def test_the_proper_octave_setting_is_applied_for_the_line():
    tabstring = '''
4|a-----------------|

5|b-----------------|
'''[1:-1]    
    notes = get_notes_for_tabstring(tabstring)
    (pitch, _) = notes[0]


def test_note_length_goes_over_line_boundaries():
    tabstring = '''
4|---------------a--|

5|b-----------------|
'''[1:-1]    
    notes = get_notes_for_tabstring(tabstring)
    (_, length) = notes[0]
    assert length == 3

def test_two_consecutive_lines_with_no_empty_line_inbetween_should_be_merged():
    tabstring = '''
5|--d----------------|
4|c------------------|
'''[1:-1]
    notes = get_notes_for_tabstring(tabstring)

    assert len(notes) == 2

    (pitch, length) = notes[0]
    assert pitch == "NOTE_C4"
    assert length == 2

    (pitch, _) = notes[1]
    assert pitch == "NOTE_D5"

def test_two_and_one_handed_lines_can_be_combined():
    tabstring = '''
5|--d----------------|
4|c------------------|

4|e------------------|
'''[1:-1]
    notes = get_notes_for_tabstring(tabstring)

    assert len(notes) == 3

    (pitch, length) = notes[0]
    assert pitch == "NOTE_C4"
    assert length == 2

    (pitch, length) = notes[1]
    assert pitch == "NOTE_D5"
    assert length == 17

    (pitch, _) = notes[2]
    assert pitch == "NOTE_E4"    