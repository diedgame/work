package Book;

public class Publication {

	
	String Title;
	String Author;
	String Journal;
	int year;
	String booktitle;
	String kind;

	public Publication(String kind,String Author, String Title, String Journal,String booktitle, int year) {
		this.Title=Title;
		this.Author=Author;
		this.Journal=Journal;
		this.year=year;
		this.booktitle=booktitle;
		this.kind=kind;

	}

	public String getKind() {
		return kind;
	}

	public void setKind(String kind) {
		this.kind = kind;
	}
	public String getTitle() {
		return Title;
	}

	public void setTitle(String title) {
		Title = title;
	}

	public String getAuthor() {
		return Author;
	}

	public void setAuthor(String author) {
		Author = author;
	}

	public String getJournal() {
		return Journal;
	}

	public void setJournal(String journal) {
		Journal = journal;
	}

	public int getYear() {
		return year;
	}

	public void setYear(int year) {
		this.year = year;
	}

	public String getBooktitle() {
		return booktitle;
	}

	public void setBooktitle(String booktitle) {
		this.booktitle = booktitle;
	}

}
