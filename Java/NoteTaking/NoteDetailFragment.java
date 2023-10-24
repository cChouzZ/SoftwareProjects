package com.example.notetaking;

import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;
import androidx.fragment.app.Fragment;

public class NoteDetailFragment extends Fragment {

        private TextView titleTextView;
        private TextView contentTextView;

        @Override
        public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
            View view = inflater.inflate(R.layout.fragment_note_detail, container, false);

            titleTextView = view.findViewById(R.id.titleTextView);
            contentTextView = view.findViewById(R.id.contentTextView);

            Bundle args = getArguments();
            if (args != null) {
                String title = args.getString("title");
                String Content = args.getString("Content");

                titleTextView.setText(title);

                contentTextView.setText(Content);
                }

            return view;
        }

    }


