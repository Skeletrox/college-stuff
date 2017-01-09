import java.util.*;


class Unit
{
	private int fstart, lstart, ffinish, lfinish, fltval, time;
	private String name;
	ArrayList<Unit> prereq;
	ArrayList<Unit> follow;
	/*
		Getter and setter functions for the data members in the class
	*/
	public void setname(String s) {name = s;}
	public void setfstart(int x) {fstart = x;}
	public void setlstart(int x) {lstart = x;}
	public void setffinish() {ffinish = fstart + time;}
	public void setlfinish(int x) {lfinish = x;}
	public void settime(int x) {time = x;}
	public void setfloat() {fltval = lstart - fstart;}
	public String getname() {return name;}
	public int getfstart() {return fstart;}
	public int getlstart() {return lstart;}
	public int getffinish() {return ffinish;}
	public int getlfinish() {return lfinish;}
	public int gettime() {return time;}
	public int getfloat() {return fltval;}
	/*
		More publicly available functions such as prerequisite task setting and
		following task setting
	*/
	public void AddPrereq(Unit z) {prereq.add(z);}
	public void AddFollow(Unit z) {follow.add(z);}
	public int GetPrereqSize() {return prereq.size();}
	public int GetFollowSize() {return follow.size();}
	public ArrayList<Unit> GetPrereq() {return prereq;}
	public ArrayList<Unit> GetFollow() {return follow;}
	public Unit()
	{
		prereq = new ArrayList<Unit>();
		follow = new ArrayList<Unit>();
		setlfinish(-1);
	}
	public void Display()
	{
		System.out.println ("Name: " + name);
		System.out.println ("Earliest start: " + fstart + " Earliest Finish: " + ffinish);
		System.out.println ("Time taken: " + time);
		System.out.println ("Latest start: " + lstart + " Latest Finish: " + lfinish);
		System.out.println ("Float value: " + fltval);
		System.out.println ("\n\n");
	}
}


public class Task
{
	static Unit start, finish;
	static void setprerfol (Unit[] u, String s, int i, int count)
	{
		int j;
		for (j=0;j<count;j++)
		{
			if (u[j].getname().equals(s))
			{
				u[j].AddFollow(u[i]);
				u[i].AddPrereq(u[j]);
			}
		}

	}

	static void BackPass (Unit u, int val)
	{
		/*
			If the prereq doesn't contain start then we shall recursively
			call this over and over again
		*/
		ArrayList<Unit> tempPrereq = u.GetPrereq();
		if (val < u.getlfinish())
			u.setlfinish(val);
		else if (u.getlfinish() == -1)
			u.setlfinish(val);
		u.setlstart(u.getlfinish() - u.gettime());
		u.setfloat();
		if (!(tempPrereq.contains(start)))
		{
			int j;
			for (j=0;j<tempPrereq.size();j++)
				BackPass (tempPrereq.get(j), u.getlstart());
		}
	}

	public static void main (String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int tasks, i, j, k, max = 0;
		String tskstr, tmp;
		System.out.println ("HAI");
		System.out.println ("Enter the number of tasks to be executed\n");
		tasks = sc.nextInt();
		Unit[] u = new Unit[tasks];
		String[] taskarray = new String[tasks];
		System.out.println ("\nEnter the task array in the following format:");
		System.out.println ("TASK NAME:DURATION:PREREQUISITE1|PREREQUISITE2|...");
		System.out.println ("\n<<Note: Enter NULL if no prerequisites>>\n");

		/*
			Clearly defining each task by slicing the task string between ':'
			Why do I need a second String[] array?
			Apparently we might need to use 2 passes: one to input each task
			And the other to identify prerequisites and followers. As Java is
			pass by reference it is very easy to do this without using many
			pointers and all that
		*/
			sc.nextLine();
		for (i=0;i<tasks;i++)
		{
			
			tskstr = sc.nextLine();
			System.out.println ("Took I/P");
			u[i] = new Unit();
			taskarray[i] = new String(tskstr);
			j=0;
			for (k=0;tskstr.charAt(k) != ':';k++){}
			tmp = tskstr.substring(j, k);
			u[i].setname(tmp);
			j=k+1;
			for (k=j;tskstr.charAt(k) != ':';k++){}
			tmp = tskstr.substring(j,k);
			u[i].settime(Integer.parseInt(tmp));
		}
		System.out.println ("\nStarting second pass for parsing\n");
		/*
			The second pass now identifies the prerequisites and followers.
			We'll use two new Unit objects: Start and Finish. Those with no
			Prerequisites will have Start as their prerequisite and those which
			have no followers will have finish as their follower.
		*/
		start = new Unit();
		finish = new Unit();
		for (i=0;i<tasks;i++)
		{
			/*
				Now we're concerned with the ith line in the taskarray. Here we'll iterate until
				exactly two instances of ':' have been found and then read the remaining part of
				the string as their prerequisites. This poses a unique problem: We'll need another
				pass to determine the number of prerequisites or followers and subsequently initialize
				that many prerequisites or followers. Instead, I'm going to use a list.
			*/
			j=0;
			k=0;
			for (j=0;k<2;j++)
			{
				if (taskarray[i].charAt(j) == ':')
					k++;
				/*
					The above segment increments k if a colon is found therefore stopping the loop at
					k=2. This also sets j at the first location after the colon.
				*/
					
			}
			for (k=j;j<taskarray[i].length();j++)
			{

				if (taskarray[i].charAt(j) == '|')
				{
				
					tmp = taskarray[i].substring(k,j);
					System.out.print (tmp + " ");
					setprerfol(u, tmp, i, tasks);
					k=j+1;
				}
					//As k referes to the starting pointer of the next string [predecessor name]
			}
			tmp = taskarray[i].substring(k,j);		//For the last case [after the last '|' is encountered]
			System.out.println (tmp + " " + k + " " + j);
			if (tmp != "NULL")
			{
									//If no prerequisites then NULL!
				setprerfol (u, tmp, i, tasks);
			}

		}
		/*
			Now we check the lengths of prerequisites and follows in order to determine whether Start and Finish
			should be added to the corresponding lists.
		*/
		for (i=0;i<tasks;i++)
		{
			if (u[i].GetPrereqSize() == 0)
			{
				System.out.println(i);
				u[i].AddPrereq(start);
			}
			if (u[i].GetFollowSize() == 0)
			{
				System.out.println(i);
				u[i].AddFollow(finish);
			}
		}

		/*
			The following code handles the forward pass.
			We'll have to take care of a few parameters here:
				1. ALL the prerequisites must finish before you start
				2. Tasks with "start" as prerequisite must have 0 as earliest start [duh]
		*/
		System.out.println ("\nForward Pass\n\n");
		for (i=0;i<tasks;i++)
		{
			ArrayList<Unit> temp = u[i].GetPrereq();
			if (temp.contains(start))
			{
				System.out.println ("Start is a prereq");
				u[i].setfstart(0);
			}
			else
			{
				
				for (j=0;j<temp.size();j++)
				{
					if (temp.get(j).gettime() > max)
						max = temp.get(j).gettime();
				}
				u[i].setfstart(max);
			}
			u[i].setffinish();
		}

		/*
			The following code handles the backward pass.
			Here we have a different set of parameters to take care of:
				1. Tasks with "finish" as follower must have the latest finish as the
				   highest value of earliest finish among them.
				2. The latest finish must be the earliest of the latest starts in each of
				   the followers.

		*/
		System.out.println ("\nBackward Pass\n\n");
		max = 0;
		for (i=0;i<tasks;i++)
		{
			if (u[i].getffinish() > max)
				max = u[i].getffinish();
		}
		/*
			Usually tasks near the end of the life cycle appear near the end of the task list.
			I guess it'd be logical to iterate backwards through the array by means of a recursive
			function.
			Gives an added advantage as the prerequisites will also be defined
		*/
		for (i=tasks-1;i>=0;i--)
		{
			if (u[i].GetFollow().contains(finish))
			{
				u[i].setlfinish(max);
				u[i].setlstart(u[i].getlfinish() - u[i].gettime());
				u[i].setfloat();
				for (j=0;j<u[i].GetPrereq().size();j++)
					BackPass(u[i].GetPrereq().get(j), u[i].getlstart());
			}
		}

		/*
			Time to Print!
		*/
		for (i=0;i<tasks;i++)
		{
			u[i].Display();
		}
	}
}