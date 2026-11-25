import java.awt.event.*;
import javax.swing.*;

class InvalidReadingException extends Exception {
    InvalidReadingException(String msg) {
        super(msg);
    }
}

public class ElectricityBill extends JFrame implements ActionListener {

    JLabel l1, l2, l3, l4, l5;
    JTextField t1, t2, t3, t4, t5;
    JButton b1;

    ElectricityBill() {

        setTitle("Electricity Bill Calculator");
        setSize(400, 450);
        setLayout(null);

        l1 = new JLabel("Consumer Name:");
        l1.setBounds(30, 30, 120, 30);
        add(l1);

        t1 = new JTextField();
        t1.setBounds(160, 30, 180, 30);
        add(t1);

        l2 = new JLabel("Previous Reading:");
        l2.setBounds(30, 80, 120, 30);
        add(l2);

        t2 = new JTextField();
        t2.setBounds(160, 80, 180, 30);
        add(t2);

        l3 = new JLabel("Current Reading:");
        l3.setBounds(30, 130, 120, 30);
        add(l3);

        t3 = new JTextField();
        t3.setBounds(160, 130, 180, 30);
        add(t3);

        l4 = new JLabel("Units Consumed:");
        l4.setBounds(30, 180, 120, 30);
        add(l4);

        t4 = new JTextField();
        t4.setBounds(160, 180, 180, 30);
        t4.setEditable(false);
        add(t4);

        l5 = new JLabel("Total Bill:");
        l5.setBounds(30, 230, 120, 30);
        add(l5);

        t5 = new JTextField();
        t5.setBounds(160, 230, 180, 30);
        t5.setEditable(false);
        add(t5);

        b1 = new JButton("Calculate Bill");
        b1.setBounds(120, 290, 150, 35);
        add(b1);

        b1.addActionListener(this);

        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
    }

    public void actionPerformed(ActionEvent e) {

        try {
            String name = t1.getText();

            int prev = Integer.parseInt(t2.getText());
            int curr = Integer.parseInt(t3.getText());

            if (curr < prev) {
                throw new InvalidReadingException(
                    "Current reading cannot be less than previous reading!"
                );
            }

            int units = curr - prev;
            double bill;

            if (units <= 100) {
                bill = units * 2;
            }
            else if (units <= 200) {
                bill = 100 * 2 + (units - 100) * 3;
            }
            else {
                bill = 100 * 2 + 100 * 3
                       + (units - 200) * 5;
            }

            t4.setText(String.valueOf(units));
            t5.setText("Rs. " + bill);

            System.out.println("Consumer Name: " + name);
            System.out.println("Units Consumed: " + units);
            System.out.println("Total Bill: Rs. " + bill);

        }
        catch (InvalidReadingException ex) {
            System.out.println("Exception: " + ex.getMessage());
        }
        catch (NumberFormatException ex) {
            System.out.println("Exception: Please enter valid readings!");
        }
        catch (Exception ex) {
            System.out.println("Exception: " + ex.getMessage());
        }
    }

    public static void main(String[] args) {
        new ElectricityBill();
    }
}
