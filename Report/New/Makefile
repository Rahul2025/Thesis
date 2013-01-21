all: Ruturaj_Y9111030_Thesis.pdf

Ruturaj_Y9111030_Thesis.pdf: Ruturaj_Y9111030_Thesis.tex References.bib
	pdflatex --halt-on-error Ruturaj_Y9111030_Thesis.tex
	bibtex Ruturaj_Y9111030_Thesis
	pdflatex --halt-on-error Ruturaj_Y9111030_Thesis.tex
	pdflatex --halt-on-error Ruturaj_Y9111030_Thesis.tex
	evince Ruturaj_Y9111030_Thesis.pdf &

clean:
	rm -rf Ruturaj_Y9111030_Thesis.dvi
	rm -rf Ruturaj_Y9111030_Thesis.pdf
	rm -rf Ruturaj_Y9111030_Thesis.bbl

clean_all: clean
	cp Ruturaj_Y9111030_Thesis.pdf BkupCopy/
	rm -rf Ruturaj_Y9111030_Thesis.pdf
	rm -rf Ruturaj_Y9111030_Thesis.log
	rm -rf Ruturaj_Y9111030_Thesis.aux
	rm -rf Ruturaj_Y9111030_Thesis.out
	rm -rf Ruturaj_Y9111030_Thesis.blg
	rm -rf Ruturaj_Y9111030_Thesis.bbl
	rm -rf Ruturaj_Y9111030_Thesis.lot
	rm -rf Ruturaj_Y9111030_Thesis.lof
