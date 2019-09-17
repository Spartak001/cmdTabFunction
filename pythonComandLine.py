from prompt_toolkit import prompt
from prompt_toolkit.history import FileHistory#for up/town history of commands
from prompt_toolkit.auto_suggest import AutoSuggestFromHistory#for suggest comand that have been written
from prompt_toolkit.completion import WordCompleter#like tab to complete words
import click
Wordscompl=WordCompleter(['select','from','other','methods in this section'],ignore_case=True)
while 1:
        inp=prompt("->",
        history=FileHistory('history.txt'),
        auto_suggest=AutoSuggestFromHistory(),
        completer=Wordscompl
        )
#       click.echo_via_pager(inp)
        print(inp)